#include <iostream>
#include <vector>
using namespace std;
bool g[100005],vis[100005],gc[100005],m[1005][1005];
int cn[100005],ce[100005];
vector<int> v[100005],ng;
void dfs(int node,int h)
{
	if (vis[node])
	return;
	vis[node]=1;
	cn[h]++;
	gc[h]|=g[node];
	for (int i=0;i<v[node].size();i++)
	{
		ce[h]+=m[node][v[node][i]];
		m[node][v[node][i]]=0;
		m[v[node][i]][node]=0;
		dfs(v[node][i],h);
	}
}
int main()
{
	int n,e,k;
	cin >> n >> e >> k;
	while (k--)
	{
		int a;
		cin >> a;
		g[a]=1;
	}
	while (e--)
	{
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		m[a][b]=1;
		m[b][a]=1;
	}
	int ans=0,mx=0;
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			dfs(i,i);
			if (gc[i])
			mx=max(mx,cn[i]);
			else
			ng.push_back(i);
			ans+=cn[i]*(cn[i]-1)/2-ce[i];
		}
	}
	int cum=0;
	for (int i=0;i<ng.size();i++)
	{
		ans+=cn[ng[i]]*cum;
		cum+=cn[ng[i]];
	}
	cout << ans+cum*mx;
}