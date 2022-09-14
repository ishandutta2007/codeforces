#include<cstdio>
using namespace std;
const long long mod=1e9+7;
int T,N,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		long long ans=1;
		for(int i=0;i<K;i++)ans=ans*N%mod;
		printf("%lld\n",ans);
	}
}