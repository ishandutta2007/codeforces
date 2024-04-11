#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1e9 + 7;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
const int MX = 500000;
const int SZ = MX * 4;

vector<int> cm;

int get(int x) {
	return lower_bound(cm.begin(), cm.end(), x) - cm.begin();
}

ll k;
int n, m;

vector<pair<int, int> > vv[2];

vector<int> go[MX][2];
ll dd[SZ][2];
ll sm[SZ][2];

void push(int v, int tl, int tr, int m, int k) {
	if (dd[v][k] == -1)
		return;
	dd[v * 2 + 1][k] = dd[v][k];
	sm[v * 2 + 1][k] = (m - tl) * dd[v][k] % MOD;
	dd[v * 2 + 2][k] = dd[v][k];
	sm[v * 2 + 2][k] = (tr - m) * dd[v][k] % MOD;
	dd[v][k] = -1;
}

void st(int v, int tl, int tr, int k, int l, int r, ll x) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		dd[v][k] = x;
		sm[v][k] = x * (tr - tl) % MOD;
		return;
	}
	int m = (tl + tr) >> 1;
	push(v, tl, tr, m, k);
	st(v * 2 + 1, tl, m, k, l, r, x);
	st(v * 2 + 2, m, tr, k, l, r, x);
	sm[v][k] = (sm[v * 2 + 1][k] + sm[v * 2 + 2][k]) % MOD;
}

ll get(int v, int tl, int tr, int k, int l, int r) {
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && tr <= r)
		return sm[v][k];
	int m = (tl + tr) >> 1;
	push(v, tl, tr, m, k);
	return (get(v * 2 + 1, tl, m, k, l, r) + get(v * 2 + 2, m, tr, k, l, r)) % MOD;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> k >> n >> m;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		cm.push_back(l);
		cm.push_back(r + 1);
		vv[0].push_back(make_pair(l, r));
	}
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		cm.push_back(l);
		cm.push_back(r + 1);
		vv[1].push_back(make_pair(l, r));
	}
	for (int i = 0; i < SZ; ++i)
		dd[i][0] = dd[i][1] = -1;
	cm.push_back(1);
	cm.push_back(k + 1);
	sort(cm.begin(), cm.end());
	cm.resize(unique(cm.begin(), cm.end()) - cm.begin());
	for (auto g: vv[0]) {
		go[get(g.first)][0].push_back(get(g.second + 1));
	}
	for (auto g: vv[1]) {
		go[get(g.first)][1].push_back(get(g.second + 1));
	}
	ll cur = 1;
	for (int i = 0; i < cm.size() - 1; ++i) {
		st(0, 0, cm.size(), 0, 0, i, 0);
		st(0, 0, cm.size(), 1, 0, i, 0);
		ll len = cm[i + 1] - cm[i];
		ll c = pw(2, len) - 2;
		if (c < 0)
			c += MOD;
		ll ncur = (cur + get(0, 0, cm.size(), 0, 0, cm.size()) + get(0, 0, cm.size(), 1, 0, cm.size())) * c % MOD;
		ll s[2];
		for (int j = 0; j < 2; ++j)
			s[j] = get(0, 0, cm.size(), j, 0, cm.size());
		for (int j = 0; j < 2; ++j) {
			int mn = cm.size();
			for (int k: go[i][j])
				mn = min(mn, k - 1);
			ll g = (get(0, 0, cm.size(), j, mn, cm.size()) + s[j ^ 1] + cur) % MOD;
			st(0, 0, cm.size(), j, mn, cm.size(), 0);
			if (mn == cm.size()) {
				ncur = (ncur + g) % MOD;
			}
			else {
				st(0, 0, cm.size(), j, mn, mn + 1, g);
			}
		}
		cur = ncur;
	}
	cout << cur << "\n";
	return 0;
}