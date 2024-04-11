#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> dp0, dp1, dpans;
vector <vector <int> > g;
vector <int> a, b, c;
void dfs(int v, int p = -1, int val = a[0])
{
	val = min(val, a[v]);
	if(b[v] != c[v])
	{
		if(b[v] == 0)
		{
			dp0[v]++;
		}
		else
		{
			dp1[v]++;
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs(to, v, val);
			dp0[v] += dp0[to];
			dp1[v] += dp1[to];
			dpans[v] += dpans[to];
		}
	}
	int t = min(dp0[v], dp1[v]);
	dpans[v] += t * val * 2;
	dp0[v] -= t;
	dp1[v] -= t;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    dp0.resize(n);
    dp1.resize(n);
    dpans.resize(n);
    g.resize(n);
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i] >> b[i] >> c[i];
	}
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
	if(dp0[0] != 0 || dp1[0] != 0)
	{
		cout << "-1";
		return 0;
	}
	cout << dpans[0];
    return 0;
}