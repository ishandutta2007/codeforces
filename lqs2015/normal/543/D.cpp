#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const long long mod=1e9+7;
long long n,x,dp[222222],ans[222222],prei,preto;
vector<long long> g[222222];
long long binpow(long long a,long long t)
{
	long long res=1,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
void dfs(long long i,long long fa)
{
	dp[i]=1;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		dp[i]=dp[i]*(dp[to]+1)%mod;
	}
}
void doit(long long i,long long fa)
{
	ans[i]=dp[i];
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa) continue;
		long long prei=dp[i],preto=dp[to];
		if (dp[i]==0 && dp[to]==mod-1)
		{
			dp[i]=1;
			for (int k=0;k<g[i].size();k++)
			{
				int tooo=g[i][k];
				if (tooo==to) continue;
				dp[i]=dp[i]*(dp[tooo]+1)%mod;
			}
			dp[to]=dp[to]*(dp[i]+1)%mod;
			
		}
		else
		{
			dp[i]=dp[i]*binpow(dp[to]+1,mod-2)%mod;
			dp[to]=dp[to]*(dp[i]+1)%mod;
		}
		doit(to,i);
		dp[i]=prei;
		dp[to]=preto;
	}
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=2;i<=n;i++)
	{
		scanf("%I64d",&x);
		g[x].push_back(i);
		g[i].push_back(x); 
	}
	dfs(1,0);
	doit(1,0);
	for (long long i=1;i<=n;i++) printf("%I64d ",ans[i]);
	printf("\n");
	return 0;
}