#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

const ll MOD = 998244353;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

const int N = 210000;

int rmq[N * 4];

const int MX = 2 * N;

ll fc[MX];
ll bfc[MX];

void init() {
	fc[0] = 1;
	for (int i = 1; i < MX; ++i) {
		fc[i] = (fc[i - 1] * i) % MOD;
	}
	bfc[MX - 1] = pw(fc[MX - 1], MOD - 2);
	for (int i = MX - 2; i >= 0; --i) {
		bfc[i] = (bfc[i + 1] * (i + 1)) % MOD;
	}
}

ll cnk(int n, int k) {
	if (k > n) {
		return 0;
	}
	return fc[n] * bfc[n - k] % MOD * bfc[k] % MOD;
}

void build(int v, int tl, int tr) {
	rmq[v] = tr - tl;
	if (tl + 1 == tr) {
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
}

void add(int v, int tl, int tr, int x, int d) {
	rmq[v] += d;
	if (tl + 1 == tr) {
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m) {
		add(v * 2 + 1, tl, m, x, d);
	} else {
		add(v * 2 + 2, m, tr, x, d);
	}
}

int getK(int v, int tl, int tr, int k) {
	if (tl + 1 == tr) {
		return tl;
	}
	int m = (tl + tr) >> 1;
	if (rmq[v * 2 + 1] >= k) {
		return getK(v * 2 + 1, tl, m, k);
	} else {
		return getK(v * 2 + 2, m, tr, k - rmq[v * 2 + 1]);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> vv;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		vv.emplace_back(x, y);
	}
	vector<int> dec;
	reverse(ALL(vv));
	int mm = 2 * n - 1;
	for (auto [x, y] : vv) {
		int p = getK(0, 0, N, y);
		add(0, 0, N, p, -1);
		dec.push_back(p);
		if (getK(0, 0, N, y) == p + 1) {
			--mm;
		}
	}
	for (int i : dec) {
		add(0, 0, N, i, 1);
	}

	cout << cnk(mm, n) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	init();
	build(0, 0, N);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		solve();
	}
	return 0;
}