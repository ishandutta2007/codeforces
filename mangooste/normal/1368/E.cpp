#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> g(n);
		for (int i = 0; i < m; i++) {
			int v, u;
			cin >> v >> u;
			v--, u--;
			g[u].push_back(v);
		}

		vector<int> len(n, 0), ans;
		for (int i = 0; i < n; i++) {
			for (auto j : g[i]) {
				len[i] = max(len[i], len[j] == 2 ? 0 : len[j] + 1);
			}
			if (len[i] == 2) {
				ans.push_back(i);
			}
		}

		cout << ans.size() << '\n';
		for (auto el : ans) {
			cout << el + 1 << ' ';
		}
		cout << '\n';
	}
}