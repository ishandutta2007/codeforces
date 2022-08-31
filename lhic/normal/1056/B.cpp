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

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	ll n;
	ll m;
	cin >> n >> m;
	ll ans = 0;
	for (ll i = 0; i < m && i <= n; ++i) {
		for (ll j = 0; j < m && j <= n; ++j) {
			if ((i * i + j * j) % m == 0) {
				ll xi = (n - i) / m + 1;
				if (i == 0)
					--xi;
				ll xj = (n - j) / m + 1;
				if (j == 0)
					--xj;
				ans += xi * xj;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}