#include<cstdio>
#include<algorithm>
using namespace std;
int N,M;
int L[1<<17];
int p[1<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d",&L[i]);
	}
	long long sum=0;
	for(int i=M;i--;)
	{
		long long l=max(sum+1-L[i]+1,1LL);
		long long r=min(sum+1,N-i-L[i]+1LL);
		if(l<=r)
		{
			p[i]=r;
			sum=r+L[i]-1;
		}
		else
		{
			puts("-1");
			return 0;
		}
	}
	if(sum<N)puts("-1");
	else for(int i=0;i<M;i++)printf("%d%c",p[i],i+1==M?'\n':' ');
}