#include<cstdio>
#include<vector>
using namespace std;
int N,K;
vector<int>G[1<<17];
int A[1<<17],dp[1<<17][40];
void dfs1(int u,int p)
{
	dp[u][0]=A[u];
	for(int v:G[u])if(v!=p)
	{
		dfs1(v,u);
		for(int i=0;i<2*K;i++)dp[u][(i+1)%(2*K)]^=dp[v][i];
	}
}
bool ans[1<<17];
int pr[40];
void dfs2(int u,int p)
{
	if(u!=0)
	{
		for(int i=0;i<2*K;i++)dp[u][(i+1)%(2*K)]^=pr[i];
	}
	int t=0;
	for(int i=K;i<2*K;i++)t^=dp[u][i];
	ans[u]=t!=0;
	for(int v:G[u])if(v!=p)
	{
		for(int i=0;i<2*K;i++)
		{
			pr[i]=dp[u][i]^dp[v][(i+2*K-1)%(2*K)];
		}
		dfs2(v,u);
	}
}
main()
{
	scanf("%d%d",&N,&K);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	dfs1(0,-1);
	dfs2(0,-1);
	for(int i=0;i<N;i++)printf("%d%c",ans[i]?1:0,i+1==N?10:32);
}