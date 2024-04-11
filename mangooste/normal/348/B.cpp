#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll ans = 0;
vector<ll> a, dp;
vector<vector<int>> g;

pair<ll, ll> euclid(ll x, ll y) {
	if (!y) {
		return {1, 0};
	}
	pair<int, int> res = euclid(y, x % y);
	return {res.second, res.first - res.second * (x / y)};
}

void dfs(int v, int pr) {
	dp[v] = 1;
	vector<ll> cnt, d;
	for (auto u : g[v]) {
		if (u != pr) {
			dfs(u, v);
			dp[v] = dp[v] * dp[u] / __gcd(dp[v], dp[u]);
			cnt.push_back(a[u]);
			d.push_back(dp[u]);
		}
	}
	if (!cnt.size()) {
		return;
	}
	dp[v] *= cnt.size();
	ans += accumulate(cnt.begin(), cnt.end(), 0ll);
	ll x = cnt[0], dx = d[0];
	for (int i = 1; i < cnt.size() && x; i++) {
		if (cnt[i] < x) {
			swap(cnt[i], x);
			swap(d[i], dx);
		}
		ll g = __gcd(dx, d[i]);
		auto [k1, k2] = euclid(dx, d[i]);
		k1 *= -(cnt[i] - x) / g;
		ll dk1 = d[i] / g;
		if (k1 < 0) {
			k1 += dk1 * ((-k1 + dk1 - 1) / dk1);
		}
		if (k1 > 0) {
			k1 -= dk1 * (k1 / dk1);
		}
		x -= k1 * dx;
		dx = 1ll * dx * d[i] / __gcd(dx, d[i]);
	}
	a[v] = 1ll * x * cnt.size();
	ans -= a[v];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &el : a) {
		cin >> el;
	}
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dp.resize(n);
	dfs(0, 0);
	cout << ans;
}