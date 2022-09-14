#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,K;
vector<int>G[200];
int dp[200][202];
int A[200];
void dfs(int u,int p)
{
	for(int i=0;i<=K;i++)dp[u][i]=0;
	for(int v:G[u])if(v!=p)
	{
		dfs(v,u);
		for(int i=0;i<(K-1)/2;i++)
		{
			if(dp[u][i+1]<=dp[v][i]-dp[v][K-i-2])
			{
				dp[u][i+1]=dp[v][i]-dp[v][K-i-2];
			}
		}
		for(int i=(K-1)/2;i<K-1;i++)
		{
			dp[u][i+1]+=dp[v][i];
		}
		dp[u][K]+=max(dp[v][K-1],dp[v][K]);
	}
	dp[u][0]=dp[u][K]+A[u];
	for(int i=0;i<(K-1)/2;i++)
	{
		dp[u][i+1]+=dp[u][K-i-1];
	}
	for(int i=K;i--;)dp[u][i]=max(dp[u][i],dp[u][i+1]);
}
main()
{
	scanf("%d%d",&N,&K);
	K++;
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans=0;
	for(int i=0;i<N;i++)
	{
		dfs(i,-1);
		ans=max(ans,dp[i][0]);
	}
	printf("%d\n",ans);
}