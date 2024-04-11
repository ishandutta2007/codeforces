#include <bits/stdc++.h>

using namespace std;

#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second

int dp[2][105][105];
tuple<int, int, int> h[2][105][105];

inline bool upd(int &x, int y)
{
	if (y < x)
	{
		x = y;
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<vector<int>> adj(n);
		for (int i = 1, j; i < n; ++i)
		{
			cin >> j;
			adj[j - 1].push_back(i);
		}

		memset(dp, 63, sizeof dp);

		vector<int> sz(n, 1);
		function<void(int)> dfs = [&](int u)
		{
			dp[0][u][1] = dp[1][u][1] = 0;
			for (auto v : adj[u])
			{
				dfs(v);
				for (int i = sz[u]; i > 0; --i)
					for (int j = 1; j <= sz[v]; ++j)
					{
						if (upd(dp[1][u][i + j], dp[1][u][i] + dp[1][v][j] + 2))
							h[1][u][i + j] = { 1, v, j };
						if (upd(dp[0][u][i + j], dp[0][u][i] + dp[1][v][j] + 2))
							h[0][u][i + j] = { 1, v, j };
						if (upd(dp[0][u][i + j], dp[1][u][i] + dp[0][v][j] + 1))
							h[0][u][i + j] = { 0, v, j };
					}
				sz[u] += sz[v];
			}
		};
		dfs(0);

		vector<int> p;
		function<void(int, int, bool)> dfs2 = [&](int u, int x, bool r)
		{
			p.push_back(u);
			int ch = -1, cnt;
			while (x > 1)
			{
				int d, v, j;
				tie(d, v, j) = h[r][u][x];
				x -= j;
				if (d == 0)
				{
					r = true;
					ch = v;
					cnt = j;
					continue;
				}
				dfs2(v, j, d);
				p.push_back(u);
			}
			if (ch != -1)
				dfs2(ch, cnt, false);
		};
		dfs2(0, k, false);
		cout << dp[0][0][k] << "\n";
		for (auto &i : p)
			cout << i + 1 << " \n"[&i==&p.back()];
	}

	return 0;
}