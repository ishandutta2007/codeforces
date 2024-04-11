#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
vector <int> dp0, dp1;
int ans1 = 1, ans2;
void dfs(int v, int p = -1)
{
	int go_to = 0;
	int cnt = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs(to, v);
			go_to++;
			if(dp0[to])
			{
				dp1[v] = 1;
			}
			if(dp1[to])
			{
				dp0[v] = 1;
			}
		}
		if(g[to].size() == 1)
		{
			cnt++;
		}
	}
	if(cnt != 0)
	{
		ans2 -= cnt - 1;
	}
	if(dp0[v] && (dp1[v] || p != -1 && g[p].size() == 1))
	{
		ans1 = 3;
	}
	if(go_to == 0)
	{
		dp0[v] = 1;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	ans2 = n - 1;
	g.resize(n);
	dp0.resize(n, 0);
	dp1.resize(n, 0);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	cout << ans1 << " " << ans2;
    return 0;
}