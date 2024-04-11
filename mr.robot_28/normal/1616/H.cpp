#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)a.size()
const int N = 2e5;
const int mod = 998244353;

ll pow1[N];
int n, x;

ll dfs1(vector <int> p, vector <int> q, int idx) {
	if (idx == -1 || !sz(p) || !sz(q)) {
		return pow1[sz(p) + sz(q)] - 1;
	}
	vector <int> p0, p1, q0, q1;
	for (auto v : p) {
		if ((1 << idx) & v) {
			p1.push_back(v);
		}
		else {
			p0.push_back(v);
		}
	}
	for (auto v : q) {
		if ((1 << idx) & v) {
			q1.push_back(v);
		}
		else {
			q0.push_back(v);
		}
	}
	if ((1 << idx) & x) {
		return (dfs1(p0, q1, idx - 1) + 1) * (dfs1(p1, q0, idx - 1) + 1) % mod  - 1;
	}
	else {
		ll ans = (dfs1(p0, q0, idx - 1) + dfs1(p1, q1, idx - 1)) % mod;
		ans += (2 * mod + pow1[sz(q0) + sz(q1)] - pow1[sz(q0)] - pow1[sz(q1)] + 1) % mod;
		ans += (2 * mod + pow1[sz(p0) + sz(p1)] - pow1[sz(p0)] - pow1[sz(p1)] + 1) % mod;
		ans %= mod;
		return ans;
	}
}

ll dfs2(vector <int> p, int idx) {
	if (sz(p) == 0) {
		return 0;
	}
	if (idx == -1) {
		return pow1[sz(p)] - 1;
	}
	vector <int> p0, p1;
	for (auto v : p) {
		if ((1 << idx) & v) {
			p1.push_back(v);
		}
		else {
			p0.push_back(v);
		}
	}
	if((1 << idx) & x) {
		return dfs1(p0, p1, idx - 1);
	}
	return (dfs2(p0, idx - 1) + dfs2(p1, idx - 1)) % mod;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pow1[0] = 1;
	for (int i = 1; i < N; i++) {
		pow1[i] = 1LL * pow1[i - 1] * 2 % mod;
	}
	cin >> n >> x;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << (mod + dfs2(a, 29)) % mod;
	return 0;
}