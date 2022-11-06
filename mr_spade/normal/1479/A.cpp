#include<cstdio>
const int N=1e5+5;
int n;
int a[N];
signed main()
{
	int x,y,z,t,x1,y1,z1;
	register int i;
	scanf("%d",&n);a[0]=a[n+1]=n+1;
	if(n<=100)
	{
		for(i=1;i<=n;i++)
			printf("? %d\n",i),fflush(stdout),scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
			if(a[i]<a[i-1]&&a[i]<a[i+1])
				return printf("! %d\n",i),0;
	}
	printf("? %d\n",1),fflush(stdout),scanf("%d",&a[1]);
	printf("? %d\n",2),fflush(stdout),scanf("%d",&a[2]);
	printf("? %d\n",n-1),fflush(stdout),scanf("%d",&a[n-1]);
	printf("? %d\n",n),fflush(stdout),scanf("%d",&a[n]);
	if(a[1]<a[2])
		return printf("! %d\n",1),0;
	if(a[n-1]>a[n])
		return printf("! %d\n",n),0;
	if(a[2]<a[n])
		x=1,y=2,z=n;
	else
		x=1,y=n-1,z=n;
	while(y-x>1||z-y>1)
	{
		if(y-x>z-y)
		{
			t=(x+y)/2;
			printf("? %d\n",t),fflush(stdout),scanf("%d",&a[t]);
			if(a[t]<a[y])
				x1=x,y1=t,z1=y;
			else if(a[y]<a[t])
				x1=t,y1=y,z1=z;
		}
		else
		{
			t=(y+z)/2;
			printf("? %d\n",t),fflush(stdout),scanf("%d",&a[t]);
			if(a[t]<a[y])
				x1=y,y1=t,z1=z;
			else if(a[y]<a[t])
				x1=x,y1=y,z1=t;
		}
		x=x1;y=y1;z=z1;
	}
	return printf("! %d\n",y),0;
}