#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, root;
vector <vector <int> > g,par, sub, dp;
void dfs(int u)
{
	sub[root][u] = 1;
	for(int i = 0; i < g[u].size(); i++)
	{
		if(g[u][i] == par[root][u])
		{
			continue;
		}
		par[root][g[u][i]] = u;
		dfs(g[u][i]);
		sub[root][u] += sub[root][g[u][i]];
	}
}
int getdp(int u, int v)
{
	if(u == v)
	{
		return 0;
	}
	if(dp[u][v] != -1) return dp[u][v];
	int res =  sub[u][v] * sub[v][u] + max(getdp(par[v][u], v), getdp(u, par[u][v]));
	return dp[u][v] = res;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	g.resize(n);
	par.resize(n, vector <int> (n, -1));
	sub.resize(n, vector <int> (n, 0));
	dp.resize(n, vector <int> (n, -1));
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int u = 0; u < n; u++)
	{
		root = u;
		dfs(u);
	}
	int ans = 0;
	for(int u =0; u < n; u++)
	{
		for(int v = 0; v < n; v++)
		{
			ans = max(ans, getdp(u, v));
		}
	}
	cout << ans;
	return 0;
}