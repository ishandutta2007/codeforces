#include<cstdio>
using namespace std;
int N;
int L1,L2,R2,R1;
int ask(int k)
{
	if(k==0||k==N+1)return(int)1e9;
	printf("? %d\n",k);
	fflush(stdout);
	int a;
	scanf("%d",&a);
	return a;
}
main()
{
	scanf("%d",&N);
	if(N==1)
	{
		puts("! 1");
		fflush(stdout);
		return 0;
	}
	L1=R1=1e9;
	L2=ask(1);
	R2=ask(N);
	int l=1,r=N;
	while(r-l>5)
	{
		int mid=(l+r)/2;
		int x=ask(mid);
		int y=ask(mid+1);
		if(x<y)
		{
			r=mid;
			R2=x;
			R1=y;
		}
		else
		{
			l=mid+1;
			L2=y;
			L1=x;
		}
	}
	int x=L1,y=L2;
	for(int k=l;k<=r;k++)
	{
		int z=ask(k+1);
		if(x>y&&y<z)
		{
			printf("! %d\n",k);
			fflush(stdout);
			return 0;
		}
		x=y;
		y=z;
	}
}