#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
#include <set>
using namespace std;
map<pair<int,int>,bool> br;
vector<pair<int,int> > e;
set<pair<int,int> > s;
vector<int> v[300005],v2[300005];
int disc[300005],low[300005],t;
void dfs(int node,int p)
{
	disc[node]=++t;
	low[node]=disc[node];
	for (int u:v[node])
	{
		if (!disc[u])
		{
			dfs(u,node);
			low[node]=min(low[node],low[u]);
			if (low[u]>disc[node])
			{
				br[{u,node}]=1;
				br[{node,u}]=1;
			}
		}
		else if (u!=p)
		low[node]=min(low[node],disc[u]);
	}
}
int c[300005],comp;
bool vis[300005];
void dfs2(int node)
{
	if (vis[node])
	return;
	vis[node]=1;
	c[node]=comp;
	for (int u:v[node])
	{
		if (!br[{u,node}])
		dfs2(u);
	}
}
int dp[300005],ans;
void dfs3(int node,int p)
{
	vector<int> tmp;
	for (int u:v2[node])
	{
		if (u!=p)
		{
			dfs3(u,node);
			tmp.push_back(dp[u]);
		}
	}
	sort(tmp.begin(),tmp.end());
	reverse(tmp.begin(),tmp.end());
	if (!tmp.empty())
	{
		dp[node]=tmp[0]+1;
		ans=max(ans,dp[node]);
	}
	if (tmp.size()>1)
	ans=max(ans,tmp[0]+tmp[1]+2);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		e.push_back({a,b});
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			comp++;
			dfs2(i);
		}
	}
	for (auto p:e)
	{
		int f=c[p.first],t=c[p.second];
		if (f==t)
		continue;
		if (f>t)
		swap(f,t);
		s.insert({f,t});
	}
	for (auto p:s)
	{
		v2[p.first].push_back(p.second);
		v2[p.second].push_back(p.first);
	}
	memset(vis,0,sizeof(vis));
	dfs3(1,0);
	printf("%d",ans);
}