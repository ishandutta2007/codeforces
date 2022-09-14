#include<cstdio>
using namespace std;
int T,N,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		long long INF=1e18;
		long long ans=INF;
		for(int i=0;i<=9;i++)
		{
			int T=0,c=0;
			for(int j=0;j<=K;j++)
			{
				if(i+j<=9)
				{
					T+=i+j;
					c++;
				}
				else T+=1+(i+j)%10;
			}
			for(int k=0;T+9*k*c<=N;k++)
			{
				int L=N-T-9*k*c;
				if(L%(K+1)!=0)continue;
				L/=K+1;
				long long now=i,p=1;
				for(int l=0;l<k;l++)
				{
					p*=10;
					now+=p*9;
				}
				int lim=8;
				while(L)
				{
					p*=10;
					int t=L<lim?L:lim;
					now+=p*t;
					L-=t;
					lim=9;
				}
				if(ans>now)ans=now;
			}
		}
		if(ans==INF)puts("-1");
		else printf("%lld\n",ans);
	}
}