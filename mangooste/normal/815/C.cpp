#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;

int n;
vector<vector<int>> g;
vector<int> c, d, sz;
vector<vector<ll>> dp0, dp1;

void dfs(int v) {
	sz[v] = 1;
	for (auto u : g[v]) {
		dfs(u);
		sz[v] += sz[u];
	}

	dp0[v][0] = dp1[v][0] = 0;
	dp1[v][1] = c[v];

	int cur_size = 1;

	for (auto u : g[v]) {
		vector<ll> was0 = dp0[v], was1 = dp1[v];

		for (int i = 1; i <= sz[u]; i++) {
			for (int j = 0; j <= cur_size && j + i <= n; j++) {
				dp0[v][j + i] = min(dp0[v][j + i], dp0[u][i] + was0[j]);
				dp1[v][j + i] = min(dp1[v][j + i], dp1[u][i] + was1[j]);
			}
		}

		cur_size += sz[u];
	}

	for (int i = n; i; i--) {
		dp0[v][i] = min(INF, dp0[v][i - 1] + c[v] - d[v]);
	}

	for (int i = 1; i <= cur_size; i++) {
		dp0[v][i] = min(dp0[v][i], dp1[v][i]);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	ll b;
	cin >> n >> b;

	g.resize(n);
	c.resize(n);
	d.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> c[i] >> d[i];
		if (i) {
			int x;
			cin >> x;
			g[x - 1].push_back(i);
		}
	}

	sz.resize(n);
	dp0.resize(n, vector<ll>(n + 1, INF));
	dp1.resize(n, vector<ll>(n + 1, INF));

	dfs(0);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dp0[0][i] <= b) {
			ans = i;
		}
	}

	cout << ans << '\n';
}