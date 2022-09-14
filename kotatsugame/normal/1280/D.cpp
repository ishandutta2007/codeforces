#include<cstdio>
#include<vector>
using namespace std;
int T,N,M;
vector<int>G[3030];
pair<int,long long>dp[3030][3030];
pair<int,long long>tmp[3030];
int S[3030];
int dfs(int u,int p)
{
	int ch=1;
	for(int j=0;j<=M;j++)dp[u][j]=make_pair(-1,0);
	dp[u][0]=make_pair(0,S[u]);
	for(int v:G[u])if(v!=p)
	{
		int c=dfs(v,u);
		for(int i=min(ch+c,M);i>=0;i--)tmp[i]=make_pair(-1,0);
		for(int i=min(ch-1,M);i>=0;i--)for(int j=0;j<=c&&i+j<=M;j++)
		{
			tmp[i+j]=max(tmp[i+j],
				make_pair(
					dp[u][i].first+dp[v][j].first,
					dp[u][i].second+dp[v][j].second
				)
			);
		}
		ch+=c;
		for(int i=min(ch,M);i>=0;i--)dp[u][i]=tmp[i];
	}
	for(int i=min(ch-1,M-1);i>=0;i--)
	{
		dp[u][i+1]=max(dp[u][i+1],
			make_pair(
				dp[u][i].first+(dp[u][i].second>0),
				0LL
			)
		);
	}
	return ch;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=0;i<N;i++)scanf("%d",&S[i]);
		for(int i=0;i<N;i++)
		{
			int w;
			scanf("%d",&w);
			S[i]=w-S[i];
		}
		for(int i=0;i<N-1;i++)
		{
			int a,b;scanf("%d%d",&a,&b);
			a--,b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs(0,-1);
		printf("%d\n",dp[0][M-1].first+(dp[0][M-1].second>0));
	}
}