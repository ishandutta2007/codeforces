#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> dep;
vector<array<int, 2>> dp;

void dfs(int v, int pr) {
	dp[v] = {0, -1};
	for (auto u : g[v])
		if (u != pr) {
			dep[u] = dep[v] + 1;
			dfs(u, v);
			int now = dp[u][0] + 1;
			for (int i = 0; i < 2; i++)
				if (dp[v][i] < now)
					swap(now, dp[v][i]);
		}
}

inline void Alice() {
	cout << "Alice\n";
}

inline void Bob() {
	cout << "Bob\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, a, b, da, db;
		cin >> n >> a >> b >> da >> db;
		a--, b--;
		{
			g = vector<vector<int>>(n);
			dep = vector<int>(n);
			dp = vector<array<int, 2>>(n);
		}
		for (int i = 0; i < n - 1; i++) {
			int v, u;
			cin >> v >> u;
			v--, u--;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		dfs(a, a);
		if (dep[b] <= da)
			Alice();
		else if (2 * da >= db)
			Alice();
		else {
			int d = 0;
			for (int i = 0; i < n; i++)
				d = max(d, dp[i][0] + dp[i][1]);
			if (2 * da >= d)
				Alice();
			else
				Bob();
		}
	}
}