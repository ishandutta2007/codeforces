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

const ll MOD = 1e9 + 7;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
const int MAXN = 120000;

int k;
ll a[MAXN];

ll pw2(ll x) {
	ll ans = x;
	for (int i = 0; i < k; ++i)
		ans = pw(ans, a[i]);
	return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> k;
	for (int i = 0; i < k; ++i)
		cin >> a[i];
	ll p = pw2(2) * pw(2, MOD - 2) % MOD + pw2(MOD - 1);
	p %= MOD;
	p = p * pw(3, MOD - 2) % MOD;
	ll q = pw2(2) * pw(2, MOD - 2) % MOD;
	cout << p << "/" << q << "\n";
	return 0;
}