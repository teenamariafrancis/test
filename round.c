#include<stdio.h>
struct pr
{	
	int pid,bt,et,ft,tat,wt,rem;
}a[10];
int main()
{
	int i,n,q,total=0,t=0;
	printf("Enter the no of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the process id :");
		scanf("%d",&a[i].pid);
		printf("enter burst time :");
		scanf("%d",&a[i].bt);
		total=total+a[i].bt;
		a[i].rem=a[i].bt;
	}
	printf("enter the quantum");
	scanf("%d",&q);
	i=0;
	printf("pid\tremaining time\n");
	while(total>0)
	{
		if(q<=a[i].rem)
		{
			a[i].rem=a[i].rem-q;
			total=total-q;
			t=t+q;
			if(a[i].rem==0)
				a[i].ft=t;

		}
		else if(q>a[i].rem && a[i].rem!=0)
		{
			total=total-a[i].rem;
			t=t+a[i].rem;
			a[i].rem=0;
				a[i].ft=t;

		}
		printf("%d\t%d\n",a[i].pid,a[i].rem);
		i++;
		if(i>n-1)
			i=0;
		}
		printf("pid\tbt\trt\tet\tft\twt\ttat\n");
		a[0].et=0;
		a[0].tat=a[0].ft;
		a[0].wt=a[0].tat-a[0].bt;
		for(i=1;i<n;i++)
		{
			if(q<a[i-1].bt)
				a[i].et=a[i-1].et+q;
			else
				a[i].et=a[i-1].et+a[i-1].bt;
			a[i].tat=a[i].ft;
			a[i].wt=a[i].tat+a[i].bt;
		}
		for(i=0;i<n;i++)
			printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n",a[i].pid,a[i].bt,a[i].rem,a[i].et,a[i].ft,a[i].wt,a[i].tat);
	return 0;
}

