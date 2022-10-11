#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<set<int>> g(n);
		for (int i = 0; i < n - 1; i++) {
			int v, u;
			cin >> v >> u;
			v--, u--;
			g[v].insert(u);
			g[u].insert(v);
		}
		set<pair<int, int>, greater<pair<int, int>>> st;
		vector<int> cnt(n, 0);
		for (int i = 0; i < n; i++) {
			for (auto j : g[i]) {
				cnt[i] += (g[j].size() == 1);
			}
			st.insert({cnt[i], i});
		}
		vector<char> used(n, 0);
		int ans = 0;
		while (st.size()) {
			auto [now, v] = *st.begin();
			st.erase(st.begin());
			if (used[v] || now < k) {
				continue;
			}
			vector<int> vers;
			for (auto u : g[v]) {
				if (g[u].size() == 1) {
					vers.push_back(u);
				}
			}
			ans += vers.size() / k;
			for (int i = 0; i < (vers.size() / k) * k; i++) {
				g[v].erase(vers[i]);
				used[vers[i]] = 1;
			}
			cnt[v] = vers.size() % k;
			if (g[v].size() == 1) {
				int u = *g[v].begin();
				st.erase({cnt[u], u});
				cnt[u]++;
				st.insert({cnt[u], u});
			}
			st.insert({cnt[v], v});
		}
		cout << ans << '\n';
	}
}