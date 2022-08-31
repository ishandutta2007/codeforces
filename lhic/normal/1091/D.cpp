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


const ll MOD = 998244353;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

ll n;
ll fc[1200000];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	fc[0] = 1;
	for (int i = 1; i <= n; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	ll ans = fc[n];
	for (int i = 0; i < n; ++i) {
		ans = (ans + fc[n] - fc[n] * pw(fc[i], MOD - 2)) % MOD;
		if (ans < 0)
			ans += MOD;
	}
	cout << ans << "\n";
	return 0;
}