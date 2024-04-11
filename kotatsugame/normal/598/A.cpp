#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		long long ans=(long long)N*(N+1)/2;
		for(int k=0;1LL<<k<=N;k++)
		{
			ans-=2LL<<k;
		}
		printf("%lld\n",ans);
	}
}