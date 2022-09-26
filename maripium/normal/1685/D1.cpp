#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> P(N); for (int &p : P) cin >> p, --p;
		vector<int> par(N); iota(par.begin(), par.end(), 0);
		vector<vector<int>> ans(N);
		vector<bool> visited(N);
		for (int s = 0; s < N; ++s) {
			if (visited[s]) continue;
			int v = s;
			while (!visited[v]) {
				ans[s].push_back(v);
				visited[v] = true;
				par[v] = s;
				v = P[v];
			}
		}

		auto get_par = [&](int v) {
			while (v != par[v]) {
				v = par[v] = par[par[v]];
			}
			return v;
		};

		for (int i = 0; i + 1 < N; ++i) {
			int v = get_par(i);
			int u = get_par(i + 1);

			if (v != u) {
				vector<int> nans;
				int jv = 0;
				int ju = 0;
				while (ans[v][jv] != i) jv++;
				while (ans[u][ju] != i + 1) ju++;
				for (int j = 0; j < int(ans[v].size()); ++j) nans.push_back(ans[v][(j + jv) % int(ans[v].size())]);
				for (int j = 0; j < int(ans[u].size()); ++j) nans.push_back(ans[u][(j + ju) % int(ans[u].size())]);
				ans[v] = nans;
				ans[u] = {};
				par[u] = v;
			}
		}

		assert(ans[0].size() == N);
		reverse(ans[0].begin(), ans[0].end());
		for (int v : ans[0]) cout << v + 1 << ' '; cout << '\n';
	}
	return 0;
}