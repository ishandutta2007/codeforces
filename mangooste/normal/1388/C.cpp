#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool ok;
vector<int> p, h;
vector<vector<int>> g;

pair<int, int> dfs(int v, int pr) {
	int pos = p[v], neg = 0;

	for (auto u : g[v]) {
		if (u != pr) {
			auto [loc_pos, loc_neg] = dfs(u, v);
			pos += loc_pos;
			neg += loc_neg;
		}
	}

	h[v] += neg;

	ok &= pos >= h[v];
	ok &= (pos - h[v]) % 2 == 0;

	int delta = (pos - h[v]) / 2;
	pos -= delta;
	neg += delta;

	ok &= (pos >= 0);

//	cout << "v = " << v + 1 << " ok = " << ok << endl;

	return {pos, neg};
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		p.clear();
		h.clear();
		g.clear();
		ok = true;

		int n, m;
		cin >> n >> m;

		p.resize(n);
		for (auto &el : p) {
			cin >> el;
		}

		h.resize(n);
		for (auto &el : h) {
			cin >> el;
			el *= -1;
		}

		g.resize(n);
		for (int i = 1; i < n; i++) {
			int v, u;
			cin >> v >> u;
			v--, u--;
			g[v].push_back(u);
			g[u].push_back(v);
		}

		dfs(0, 0);

		cout << (ok ? "YES\n" : "NO\n");
	}
}