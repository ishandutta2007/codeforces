#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <int> > g;
vector <vector <int> > dp;
const int cnst = 998244353;
void dfs(int v, int pred = -1)
{
	int cnt = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			dfs(g[v][i], v);
			cnt++;
		}
	}
	if(cnt == 0)
	{
		dp[v][2] = 1;
		dp[v][0] = 1;
		dp[v][1] = 0;
		return;
	}
	vector <int> ver;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			ver.push_back(g[v][i]);
		}
	}
	vector <int> pref(ver.size()), post(ver.size());
	for(int i = 0; i < ver.size(); i++)
	{
		if(i == 0)
		{
			pref[i] = dp[ver[i]][1] * 2 + dp[ver[i]][2];
			pref[i] %= cnst;
		}
		else
		{
			int k = dp[ver[i]][1] * 2 + dp[ver[i]][2];
			k %= cnst;
			pref[i] = pref[i - 1] * k % cnst;
		}
	}
	for(int i = ver.size() - 1; i >= 0; i--)
	{
		if(i == ver.size() - 1)
		{
			post[i] += dp[ver[i]][1] * 2 + dp[ver[i]][2];
			post[i] %= cnst;
		}
		else
		{
			int k = dp[ver[i]][1] * 2 + dp[ver[i]][2];
			k %= cnst;
			post[i] = post[i + 1] * k % cnst;
		}
	}
	dp[v][0] = pref[ver.size() - 1];
	int ans = 0;
	for(int i = 0; i < ver.size(); i++)
	{
		int rez = dp[ver[i]][0];
		if(i != 0)
		{
			rez *= pref[i - 1];
			rez %= cnst;
		}
		if(i != ver.size() - 1)
		{
			rez *= post[i + 1];
		}
		rez %= cnst;
		ans += rez;
		ans %= cnst;
	}
	dp[v][1] = ans % cnst;
	ans = 1;
	for(int i = 0; i< ver.size(); i++)
	{
		ans = ans * (dp[ver[i]][1] + dp[ver[i]][2]) % cnst;
	}
	dp[v][2] = ans;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	g.resize(n);
	dp.resize(n, vector <int> (3));
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	cout << (dp[0][1] + dp[0][2]) % cnst;
	return 0;
}