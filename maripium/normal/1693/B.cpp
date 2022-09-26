#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;	
		vector<vector<int>> adj(N);
		for (int i = 1; i < N; ++i) {
			int p; cin >> p;
			adj[--p].push_back(i);
		}
		vector<pair<int64_t, int64_t>> A(N);
		for (auto &a : A) cin >> a.first >> a.second;

		int ans = 0;
		function<pair<int64_t, int64_t>(int)> dfs = [&](int v) -> pair<int64_t, int64_t> {
			pair<int64_t, int64_t> ch{0, 0};
			for (int u : adj[v]) {
				auto [cl, cr] = dfs(u);
				ch.first += cl;
				ch.second += cr;
			}

			auto [l, r] = A[v];
			auto [cl, cr] = ch;

			if (l > cr) {
				ans++;
				return {l, r};
			} else if (cl > r) {
				return {l, r};
			} else {
				return {max(cl, l), min(cr, r)};
			}
		};

		dfs(0);
		cout << ans << '\n';
	}
	return 0;
}