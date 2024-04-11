#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 210000;
const ll MOD = 1e9 + 7;

int n, q;

ll a[MAXN];
ll w[MAXN];
ll sm[MAXN * 4];
ll sm2[MAXN * 4];

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		sm[v] = w[tl];
		sm2[v] = w[tl] * a[tl] % MOD;
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	sm[v] = (sm[v * 2 + 1] + sm[v * 2 + 2]);
	sm2[v] = (sm2[v * 2 + 1] + sm2[v * 2 + 2]) % MOD;
}

ll getsum(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && tr <= r)
		return sm[v];
	int m = (tl + tr) >> 1;
	return getsum(v * 2 + 1, tl, m, l, r) + getsum(v * 2 + 2, m, tr, l, r);
}

ll getsum2(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && tr <= r)
		return sm2[v];
	int m = (tl + tr) >> 1;
	return (getsum2(v * 2 + 1, tl, m, l, r) + getsum2(v * 2 + 2, m, tr, l, r)) % MOD;
}

void upd(int v, int tl, int tr, int x, ll y) {
	if (tl + 1 == tr) {
		w[tl] = y;
		sm[v] = y;
		sm2[v] = y * a[tl] % MOD;
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		upd(v * 2 + 1, tl, m, x, y);
	else
		upd(v * 2 + 2, m, tr, x, y);
	sm[v] = (sm[v * 2 + 1] + sm[v * 2 + 2]);
	sm2[v] = (sm2[v * 2 + 1] + sm2[v * 2 + 2]) % MOD;
}

int get(int v, int tl, int tr, ll rq) {
	if (tl + 1 == tr) {
		return tl;
	}
	int m = (tl + tr) >> 1;
	if (sm[v * 2 + 1] >= rq)
		return get(v * 2 + 1, tl, m, rq);
	else
		return get(v * 2 + 2, m, tr, rq - sm[v * 2 + 1]);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> a[i], a[i] -= i;
	for (int i = 0; i < n; ++i)
		cin >> w[i];
	build(0, 0, n);
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		if (x < 0) {
			x = -x;
			--x;
			upd(0, 0, n, x, y);
		}
		else {
			int l = x;
			int r = y;
			--l;
			ll sum = getsum(0, 0, n, l, r);
			ll rq = getsum(0, 0, n, 0, l) + (sum + 1) / 2;
			int pos = get(0, 0, n, rq);
			ll sml = getsum(0, 0, n, l, pos) % MOD;
			ll smr = (sum - sml) % MOD;
			ll go = getsum2(0, 0, n, pos, r) - a[pos] * smr % MOD +  a[pos] * sml % MOD - getsum2(0, 0, n, l, pos);
			go %= MOD;
			if (go < 0)
				go += MOD;
			cout << go << "\n";
		}
	}
	return 0;
}