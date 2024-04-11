#include<cstdio>
using namespace std;
const long long mod=998244353;
int N;
bool op[500];
int X[500];
long long dp[502];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		char c;
		scanf(" %c",&c);
		if(c=='-')op[i]=false;
		else
		{
			op[i]=true;
			scanf("%d",&X[i]);
		}
	}
	long long ans=0;
	for(int i=0;i<N;i++)if(op[i])
	{
		for(int k=0;k<=N+1;k++)dp[k]=0;
		dp[0]=1;
		for(int j=0;j<N;j++)
		{
			if(i==j)
			{
				for(int k=N;k>=0;k--)dp[k+1]=dp[k];
			}
			else if(op[j])
			{
				bool ad=false;
				if(X[i]>X[j]||X[i]==X[j]&&i>j)ad=true;
				if(ad)
				{
					for(int k=N;k>=0;k--)dp[k+1]=(dp[k+1]+dp[k])%mod;
				}
				else
				{
					for(int k=0;k<=N;k++)dp[k]=dp[k]*2%mod;
				}
			}
			else
			{
				dp[0]=dp[0]*2%mod;
				for(int k=0;k<=N;k++)dp[k]=(dp[k]+dp[k+1])%mod;
			}
			if(i<=j)dp[0]=0;
		}
		long long tm=0;
		for(int k=1;k<=N;k++)tm=(tm+dp[k])%mod;
		ans=(ans+tm*X[i]%mod)%mod;
	}
	printf("%lld\n",ans);
}