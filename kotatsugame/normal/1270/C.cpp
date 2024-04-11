#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int t;
int N;
int A[1<<17];
long long b[3];
void solve()
{
	long long SUM=0,XOR=0;
	for(int i=0;i<N;i++)
	{
		SUM+=A[i];
		XOR^=A[i];
	}
	b[0]=b[1]=b[2]=0;
	if(SUM&1)
	{
		b[2]|=1;
		SUM+=1;
		XOR^=1;
	}
	for(int i=1;i<62;i++)
	{
		long long test=1LL<<i;
		bool s=SUM&(1LL<<i)?true:false;
		bool x=XOR&(1LL<<(i-1))?true:false;
		if(s^x)
		{
			if(s)
			{
				b[2]|=1LL<<i;
				SUM+=1LL<<i;
				XOR^=1LL<<i;
			}
			else if(x)
			{
				b[0]|=1LL<<(i-1);
				b[1]|=1LL<<(i-1);
				SUM+=1LL<<i;
			}
		}
	}
}
main()
{
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		solve();
		puts("3");
		for(int j=0;j<3;j++)printf("%lld%c",b[j],j==2?'\n':' ');
	}
}