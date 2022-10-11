#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 701;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v][u] = g[u][v] = 1;
	}

	vector<vector<int>> cnt(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (g[i][k] && g[j][k]) {
					cnt[i][j]++;
					cnt[j][i]++;
				}
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int deg = accumulate(g[i].begin(), g[i].end(), 0);
		for (int j = 0; j < n; j++) {
			if (g[i][j]) {
				for (int k = 0; k < n; k++) {
					if (k != i && k != j) {
						int with_i = cnt[i][k] - g[k][j];
						int with_j = cnt[j][k] - g[k][i];
						ans += with_i * with_j;
					}
					if (g[i][k] && g[j][k]) {
						ans -= deg - 2;
					}
				}
			}
		}
	}

	cout << ans / 10 << '\n';
}