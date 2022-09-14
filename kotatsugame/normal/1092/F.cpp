#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int A[2<<17];
vector<int>G[2<<17];
long long dp[2<<17];
long long sA[2<<17];
void dfs(int u,int p)
{
	dp[u]=0;
	sA[u]=A[u];
	for(int v:G[u])if(v!=p)
	{
		dfs(v,u);
		dp[u]+=dp[v]+sA[v];
		sA[u]+=sA[v];
	}
}
long long dp2[2<<17];
void dfs2(int u,int p,long long pdp,long long psA)
{
	dp2[u]=dp[u]+pdp+psA;
	sA[u]+=psA;
	for(int v:G[u])if(v!=p)
	{
		dfs2(v,u,dp2[u]-dp[v]-sA[v],sA[u]-sA[v]);
	}
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1);
	dfs2(0,-1,0,0);
	long long ans=0;
	for(int i=0;i<N;i++)ans=max(ans,dp2[i]);
	printf("%lld\n",ans);
}