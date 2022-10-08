#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	const int64_t INF = 1e15;

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;

		vector<vector<pair<int, int>>> adj(N);
		
		vector<vector<int>> dist(N, vector<int>(N, N));
		for (int i = 0; i < M; ++i) {
			int v, u, w; cin >> v >> u >> w;
			--v, --u;
			adj[v].push_back({u, w});
			adj[u].push_back({v, w});
			dist[v][u] = dist[u][v] = 1;
		}
		for (int v = 0; v < N; ++v) dist[v][v] = 0;

		for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int64_t ans = INF;
		for (int v = 0; v < N; ++v) {
			for (auto [u, w] : adj[v]) {
				ans = min(ans, int64_t(dist[0][v] + 1 + dist[N - 1][u]) * w);
				for (int u2 = 0; u2 < N; ++u2) {
					ans = min(ans, int64_t(dist[0][u2] + dist[N - 1][u2] + 2 + dist[u][u2]) * w);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}