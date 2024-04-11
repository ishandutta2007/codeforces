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

int n, k;
int a[MAXN];
int sm[MAXN];

map<int, int> mm;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sm[0] = 0;
	for (int i = 0; i < n; ++i)
		sm[i + 1] = sm[i] ^ a[i];
	int msk = (1 << k) - 1;
	for (int i = 0; i <= n; ++i) {
		int x = sm[i];
		x = min(x, x ^ msk);
		++mm[x];
	}
	ll ans = ll(n) * ll(n + 1) / 2;
	for (auto it: mm) {
		ll x = it.second;
		ll xl = x / 2;
		ll xr = x - xl;
		ans -= xl * (xl - 1) / 2;
		ans -= xr * (xr - 1) / 2;
	}
	cout << ans << "\n";
	return 0;
}