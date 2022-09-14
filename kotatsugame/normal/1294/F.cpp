#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int>G[2<<17];
pair<int,int>dp1[2<<17];
pair<int,pair<int,int> >dp2[2<<17];
int ans=-1;
int ansv[3];
void dfs(int u,int p)
{
	dp1[u]=make_pair(0,u);
	dp2[u]=make_pair(-1,make_pair(-1,-1));
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==p)continue;
		dfs(v,u);
		if(dp2[u].first>=0)
		{
			int nxt=dp2[u].first+dp1[v].first+1;
			if(nxt>ans)
			{
				ans=nxt;
				ansv[0]=dp2[u].second.first;
				ansv[1]=dp2[u].second.second;
				ansv[2]=dp1[v].second;
			}
		}
		if(dp2[v].first>=0)
		{
			int nxt=dp1[u].first+dp2[v].first+1;
			if(nxt>ans)
			{
				ans=nxt;
				ansv[0]=dp1[u].second;
				ansv[1]=dp2[v].second.first;
				ansv[2]=dp2[v].second.second;
			}
			nxt=dp2[v].first+1;
			if(nxt>dp2[u].first)
			{
				dp2[u].first=nxt;
				dp2[u].second=dp2[v].second;
			}
		}
		{
			int nxt=dp1[u].first+dp1[v].first+1;
			if(nxt>dp2[u].first)
			{
				dp2[u].first=nxt;
				dp2[u].second.first=dp1[u].second;
				dp2[u].second.second=dp1[v].second;
			}
		}
		if(dp1[v].first+1>dp1[u].first)
		{
			dp1[u].first=dp1[v].first+1;
			dp1[u].second=dp1[v].second;
		}
	}
}
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1);
	printf("%d\n%d %d %d\n",ans,ansv[0]+1,ansv[1]+1,ansv[2]+1);
}