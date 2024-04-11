#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T;
long long N;
long long p3[40];
long long L[1<<20],R[1<<20];
main()
{
	p3[0]=1;
	for(int i=1;i<20;i++)p3[i]=p3[i-1]*3;
	for(int i=0;i<1<<10;i++)
	{
		for(int j=0;j<10;j++)if(i>>j&1)
		{
			L[i]+=p3[j];
			R[i]+=p3[10+j];
		}
	}
	sort(L,L+(1<<10));
	sort(R,R+(1<<10));
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld",&N);
		long long ans=9e18;
		int r=1<<10;
		for(int i=0;i<1<<10;i++)
		{
			while(r>0&&L[i]+R[r-1]>=N)r--;
			if(r<1<<10)ans=min(ans,L[i]+R[r]);
		}
		printf("%lld\n",ans);
	}
}