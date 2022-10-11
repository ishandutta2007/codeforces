#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	vector<int> col(n, 0), cnt(n);
	set<pair<int, int>, greater<pair<int, int>>> bad;
	for (int i = 0; i < n; i++) {
		cnt[i] = g[i].size();
		bad.emplace(cnt[i], i);
	}
	auto recalc = [&](int v) {
		bad.erase({cnt[v], v});
		cnt[v] = 0;
		for (auto u : g[v]) cnt[v] += (col[v] == col[u]);
		bad.emplace(cnt[v], v);
	};
	while (bad.size()) {
		int v = bad.begin()->second;
		bad.erase(bad.begin());
		if (cnt[v] < 2) continue;
		col[v] ^= 1;
		recalc(v);
		for (auto u : g[v]) recalc(u);
	}
	for (auto x : col) cout << x;
	cout << '\n';
}