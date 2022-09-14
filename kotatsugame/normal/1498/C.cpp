#include<cstdio>
using namespace std;
const long long mod=1e9+7;
int T,N,K;
long long cnt[1010];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		long long ans=1;
		for(int i=0;i<N;i++)cnt[i]=1;
		for(int j=1;j<K;j++)
		{
			if(j%2==1)
			{
				long long now=0;
				for(int i=N;i--;)
				{
					long long nxt=(now+cnt[i])%mod;
					cnt[i]=now;
					now=nxt;
				}
				ans=(ans+now)%mod;
			}
			else
			{
				long long now=0;
				for(int i=0;i<N;i++)
				{
					long long nxt=(now+cnt[i])%mod;
					cnt[i]=now;
					now=nxt;
				}
				ans=(ans+now)%mod;
			}
		}
		printf("%lld\n",ans);
	}
}