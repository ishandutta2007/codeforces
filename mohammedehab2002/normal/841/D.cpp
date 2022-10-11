#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
int deg[300005];
vector<int> v[300005],v2[300005];
bool vis[300005],ans[300005];
map<pair<int,int>,int> mp;
void dfs(int node)
{
	vis[node]=1;
	for (int i=0;i<v2[node].size();i++)
	{
		if (!vis[v2[node][i]])
		{
			v[node].push_back(v2[node][i]);
			dfs(v2[node][i]);
		}
	}
}
int dfs(int node,int pnode)
{
	int con=0;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		con=(con+dfs(v[node][i],node))%2;
	}
	if (deg[node]==-1 || con==deg[node])
	return 0;
	if (pnode)
	ans[mp[make_pair(node,pnode)]]=1;
	return 1;
}
bool dfs2(int node)
{
	bool found=0;
	vis[node]=1;
	if (deg[node]==-1)
	return 1;
	for (int i=0;i<v2[node].size();i++)
	{
		if (!vis[v2[node][i]])
		{
			found|=dfs2(v2[node][i]);
			if (found)
			{
				ans[mp[make_pair(node,v2[node][i])]]^=1;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	scanf("%d",&deg[i]);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v2[a].push_back(b);
		v2[b].push_back(a);
		mp[make_pair(a,b)]=i;
		mp[make_pair(b,a)]=i;
	}
	dfs(1);
	memset(vis,0,sizeof(vis));
	if (dfs(1,0))
	{
		if (!dfs2(1))
		{
			printf("-1");
			return 0;
		}
	}
	int cnt=0;
	for (int i=1;i<=m;i++)
	cnt+=ans[i];
	printf("%d\n",cnt);
	for (int i=1;i<=m;i++)
	{
		if (ans[i])
		printf("%d\n",i);
	}
}