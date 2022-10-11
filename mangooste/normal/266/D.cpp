#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 2e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> dist(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) dist[i][i] = 0;
	vector<array<int, 3>> edges;
	for (int i = 0; i < m; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		v--, u--, w *= 2;
		dist[v][u] = dist[u][v] = w;
		edges.push_back({v, u, w});
	}
	for (int m = 0; m < n; m++) {
		for (int v = 0; v < n; v++) {
			for (int u = 0; u < n; u++) {
				if (dist[v][m] != INF && dist[m][u] != INF)
					dist[v][u] = min(dist[v][u], dist[v][m] + dist[m][u]);
			}
		}
	}

	int L = 0, R = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) R = max(R, dist[i][j]);
	}
	while (R - L > 1) {
		int mid = (L + R) / 2;
		bool any = false;
		for (auto [v, u, w] : edges) {
			vector<pair<int, int>> evs;
			for (int i = 0; i < n; i++) {
				int dv = dist[i][v], du = dist[i][u];
				if (dv <= mid) evs.emplace_back(mid - dv, 1);
				if (du <= mid) evs.emplace_back(max(mid - dv + 1, w - mid + du), -1);
			}
			int bal = 0;
			for (int i = 0; i < n; i++) bal += (dist[i][v] <= mid);
			int max_bal = bal;
			sort(evs.begin(), evs.end());
			for (auto [x, t] : evs) {
				bal -= t;
				max_bal = max(max_bal, bal);
			}
			if (max_bal >= n) {
				any = true;
				break;
			}
		}
		(any ? R : L) = mid;
	}
	cout << R / 2 << "." << (R % 2) * 5 << '\n';
}