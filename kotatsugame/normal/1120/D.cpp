#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,C[2<<17];
vector<int>G[2<<17];
pair<long long,long long>dp[2<<17];
long long all[2<<17],down[2<<17];
void dfs(int u,int p)
{
	int ch=0;
	for(int v:G[u])if(v!=p)
	{
		dfs(v,u);
		ch++;
		all[u]+=dp[v].first;
		down[u]=max(down[u],dp[v].first-dp[v].second);
	}
	if(ch>0)
	{
		dp[u]=make_pair(min(all[u],all[u]-down[u]+C[u]),all[u]-down[u]);
	}
	else
	{
		dp[u]=make_pair(C[u],0);
	}
}
vector<int>ans;
bool d[2<<17];
void dfs2(int u,int p,int ok)
{
	if(ok&1&&dp[u].first==all[u]-down[u]+C[u])ans.push_back(u+1);
	int dc=0;
	for(int v:G[u])if(v!=p)dc+=d[v]=down[u]==dp[v].first-dp[v].second;
	for(int v:G[u])if(v!=p)
	{
		int nok=0;
		if(ok&2)
		{
			if(d[v])nok|=2;
			if(!d[v]||dc>1)nok|=1;
		}
		if(ok&1)
		{
			if(all[u]==dp[u].first)nok|=1;
			if(all[u]-down[u]+C[u]==dp[u].first)
			{
				if(d[v])nok|=2;
				if(!d[v]||dc>1)nok|=1;
			}
		}
		dfs2(v,u,nok);
	}
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&C[i]);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1);
	dfs2(0,-1,1);
	sort(ans.begin(),ans.end());
	printf("%lld %d\n",dp[0].first,(int)ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?10:32);
}