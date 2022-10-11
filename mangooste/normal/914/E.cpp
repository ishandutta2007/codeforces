#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> g;
string s;
vector<int> sz, cnt(1 << 20, 0);
vector<ll> ans, val;
vector<char> used;

void build_sz(int v, int pr) {
	sz[v] = 1;
	for (auto u : g[v]) {
		if (u != pr && !used[u]) {
			build_sz(u, v);
			sz[v] += sz[u];
		}
	}
}

int get_cen(int v, int pr, int sz_all) {
	for (auto u : g[v]) {
		if (u != pr && !used[u] && sz[u] * 2 > sz_all) {
			return get_cen(u, v, sz_all);
		}
	}
	return v;
}

void build_cnt(int v, int pr, int now, bool sub_mod) {
	now ^= (1 << s[v]);
	cnt[now] += 1 - 2 * sub_mod;
	for (auto u : g[v]) {
		if (u != pr && !used[u]) {
			build_cnt(u, v, now, sub_mod);
		}
	}
}

void build_val(int v, int pr, int now, ll &add_to_v) {
	now ^= (1 << s[v]);

	val[v] = cnt[now];
	for (int bit = 0; bit < 20; bit++) {
		val[v] += cnt[now ^ (1 << bit)];
	}

	add_to_v += (!now || !(now - (1 << __builtin_ctz(now))));

	for (auto u : g[v]) {
		if (u != pr && !used[u]) {
			build_val(u, v, now, add_to_v);
			val[v] += val[u];
		}
	}

	ans[v] += val[v];
}

void solve(int v) {
	build_sz(v, v);

	v = get_cen(v, v, sz[v]);
	used[v] = 1;

	cnt[0]++;
	for (auto u : g[v]) {
		if (!used[u]) {
			build_cnt(u, v, 0, false);
		}
	}

	ll add_to_v = 2;

	for (auto u : g[v]) {
		if (!used[u]) {
			build_cnt(u, v, 0, true);
			build_val(u, v, 1 << s[v], add_to_v);
			build_cnt(u, v, 0, false);
			add_to_v += val[u];
		}
	}

	ans[v] += add_to_v / 2;

	cnt[0]--;
	for (auto u : g[v]) {
		if (!used[u]) {
			build_cnt(u, v, 0, true);
		}
	}

	for (auto u : g[v]) {
		if (!used[u]) {
			solve(u);
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	g.resize(n);
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	cin >> s;
	for (auto &el : s) {
		el -= 'a';
	}

	ans.resize(n);
	used.resize(n);
	sz.resize(n);
	val.resize(n);

	solve(0);

	for (auto el : ans) {
		cout << el << ' ';
	}
	cout << '\n';
}