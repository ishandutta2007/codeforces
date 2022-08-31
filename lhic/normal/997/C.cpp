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
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 998244353;
const ll B1 = 662;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

const int MAXN = 1200000;

ll fc[MAXN];
ll bfc[MAXN];


ll cnk(int n, int k) {
	if (k > n)
		return 0;
	return fc[n] * bfc[k] % MOD * bfc[n - k] % MOD;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	ll n;
	cin >> n;
	fc[0] = 1;
	for (int i = 1; i <= n; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	bfc[n] = pw(fc[n], MOD - 2);
	for (int i = n - 1; i >= 0; --i)
		bfc[i] = (bfc[i + 1] * (i + 1)) % MOD;
	ll ans = pw(3, n * n);
	for (int i = 1; i <= n; ++i) {
		ll cur = 2 * cnk(n, i) * pw(3, i) % MOD * pw(3, n * (n - i)) % MOD;
		if (i % 2 == 0)
			ans = (ans + cur) % MOD;
		else
			ans = (ans + MOD - cur) % MOD;
	}
	for (int k = 0; k < n; ++k) {
		ll now = pw((1 - pw(3, k) + MOD) % MOD, n) - pw(MOD - pw(3, k), n);
		now %= MOD;
		if (now < 0)
			now += MOD;
		now = 3 * now * cnk(n, k) % MOD;
		if (k % 2 == 1)
			now = (MOD - now) % MOD;
		ans = (ans + now) % MOD;
	}
	ans = pw(3, n * n) - ans + MOD;
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}