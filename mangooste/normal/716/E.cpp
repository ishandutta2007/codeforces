#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, phi;
vector<vector<pair<int, int>>> g;
vector<int> sz;
vector<char> used;
ll ans = 0;
unordered_map<int, int> cnt;

int get_phi(int n) {
	phi = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i) continue;
		phi /= i;
		phi *= i - 1;
		while (n % i == 0) n /= i;
	}
	if (n != 1) {
		phi /= n;
		phi *= n - 1;
	}
	return phi;
}

inline int mult(int a, int b) {
	return (ll) a * b % m;
}

inline int add(int a, int b) {
	a += b;
	return a - m * (a >= m);
}

int power(int a, int b) {
	if (!b) return 1;
	if (b % 2) return mult(a, power(a, b - 1));
	return power(mult(a, a), b / 2);
}

void calc_sz(int v, int pr) {
	sz[v] = 1;
	for (auto [u, w] : g[v]) {
		if (u == pr || used[u]) continue;
		calc_sz(u, v);
		sz[v] += sz[u];
	}
}

int get_centroid(int v, int pr, int sz_all) {
	for (auto [u, w] : g[v]) {
		if (u == pr || used[u]) continue;
		if (sz[u] * 2 >= sz_all) return get_centroid(u, v, sz_all);
	}
	return v;
}

void calc_cnt(int v, int pr, int num, int pw, bool sub_mod) {
	cnt[num] += (sub_mod ? -1 : 1);
	if (!cnt[num]) cnt.erase(num);
	pw = mult(pw, 10);
	for (auto [u, w] : g[v]) {
		if (u == pr || used[u]) continue;
		calc_cnt(u, v, add(num, mult(pw, w)), pw, sub_mod);
	}
}

void calc_ans(int v, int pr, int num, int pw) {
	int x = mult(power(pw, phi - 1), (m - num) % m);
	assert(!add(mult(x, pw), num));
	if (cnt.find(x) != cnt.end()) ans += cnt[x];
	ans += (num == 0);
	for (auto [u, w] : g[v]) {
		if (u == pr || used[u]) continue;
		calc_ans(u, v, add(w, mult(num, 10)), mult(pw, 10));
	}
}

void solve(int v) {
	calc_sz(v, v);
	v = get_centroid(v, v, sz[v]);
	used[v] = 1;
	for (auto [u, w] : g[v]) {
		if (!used[u]) calc_cnt(u, v, w, 1 % m, false);
	}

	ans += cnt[0];
	for (auto [u, w] : g[v]) {
		if (used[u]) continue;
		calc_cnt(u, v, w, 1 % m, true);
		calc_ans(u, v, w, 10 % m);
		calc_cnt(u, v, w, 1 % m, false);
	}

	for (auto [u, w] : g[v]) {
		if (!used[u]) calc_cnt(u, v, w, 1 % m, true);
	}
	for (auto [u, w] : g[v]) {
		if (!used[u]) solve(u);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	g.resize(n);
	for (int i = 1; i < n; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		w %= m;
		g[v].emplace_back(u, w);
		g[u].emplace_back(v, w);
	}
	get_phi(m);

	used.resize(n);
	sz.resize(n);
	solve(0);
	cout << ans << '\n';
}