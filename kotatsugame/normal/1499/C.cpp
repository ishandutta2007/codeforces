#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,C[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&C[i]);
		long long ans=9e18;
		long long Ls=0,Rs=0,Lm=2e9,Rm=2e9;
		for(int i=0;i<N;i++)
		{
			if(i%2==0)
			{
				Ls+=C[i];
				Lm=min(Lm,(long long)C[i]);
			}
			else
			{
				Rs+=C[i];
				Rm=min(Rm,(long long)C[i]);
			}
			long long now=Ls+Rs+(N-i/2-1)*Lm+(N-(i+1)/2)*Rm;
			ans=min(ans,now);
		}
		printf("%lld\n",ans);
	}
}