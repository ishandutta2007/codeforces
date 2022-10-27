#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <int> > dp;
vector <vector <pair <int, int> > > g;
vector <int> mass;
vector <bool> used;
int n, m, t;
void dfs(int v)
{
	if(used[v])
	{
		return;
	}
	used[v] = true;
	for(int i = 0; i < g[v].size(); i++)
	{
		dfs(g[v][i].first);
	}
	mass.push_back(v);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> t;
    g.resize(n);
    used.resize(n);
    for(int i = 0; i < m; i++)
    {
    	int x, y, w;
    	cin >> x >> y >> w;
    	x--;
    	y--;
    	g[x].push_back({y, w});
	}
	dfs(0);
	dp.resize(n, vector <int> (n + 1, 1e9 + 1));
	dp[n - 1][1] = 0;
	for(int i = 0; i < mass.size(); i++)
	{
		int v = mass[i];
		for(int j = 0; j < g[v].size(); j++)
		{
			int to = g[v][j].first;
			int weight = g[v][j].second;
			for(int k = 1; k < n; k++)
			{
				if(dp[to][k] + weight < dp[v][k + 1])
				{
					dp[v][k + 1] = dp[to][k] + weight;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(dp[0][i] <= t)
		{
			ans = i;
		}
	}
	int v = 0;
	stack <int> t;
	cout << ans << "\n";
	while(v != n - 1)
	{
		cout << v + 1 << " ";
		for(int j = 0; j < g[v].size(); j++)
		{
			int to = g[v][j].first;
			int weight = g[v][j].second;
			if(dp[to][ans - 1] + weight == dp[v][ans])
			{
				v = to;
				break;
			}
		}
		ans--;
	}
	cout << n;
    return 0;
}