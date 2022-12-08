#include <bits/stdc++.h>

using namespace std;

int used[10000];
bool cac=false;
vector<pair<int, int> > adj[10005];
int ans[10000];
void dfs(int node)
{
	used[node]=1;
	for(auto i:adj[node])
	{
		if(used[i.first]==1)
		{
//			cout<<i.first<<endl;
			cac=true;
			ans[i.second]=1;
		}
		else
		{
			if(!used[i.first])
			dfs(i.first);
		}
	}
	used[node]=2;
}

signed main()
{
	int n, m;
	cin>>n>>m;
	for(int i=1; i<=m; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back({v,i});
	}
	for(int i=1; i<=n; i++)
	{
		if(!used[i]) dfs(i);
	}
//	cac=false;
	if(!cac)
	{
		cout<<1<<endl;
		for(int i=1; i<=m; i++)
		{
			cout<<1<<" ";
		}
	}
	else
	{
		cout<<2<<endl;
		for(int i=1; i<=m; i++)
		{
			cout<<ans[i]+1<<" ";
		}
	}
}