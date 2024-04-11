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


const ll MOD = 1e9 + 7;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

ll n;
int k;

ll dp[100];
ll bc[100];

ll get(ll p, ll c) {
	for (int i = 0; i <= c; ++i)
		dp[i] = 0;
	dp[c] = 1;
	for (int i = 0; i < k; ++i) {
		ll sum = 0;
		for (int j = c; j >= 0; --j) {
			sum = (sum + dp[j] * bc[j + 1]) % MOD;
			dp[j] = sum;
		}
	}
	ll ans = 0;
	ll cur = 1;
	for (int i = 0; i <= c; ++i) {
		ans = (ans + dp[i] * cur) % MOD;
		if (i < c)
			cur = (cur * p) % MOD;
	}
	return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	for (int i = 1; i < 100; ++i)
		bc[i] = pw(i, MOD - 2);
	cin >> n >> k;
	ll ans = 1;
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i != 0)
			continue;
		int cnt = 0;
		while (n % i == 0)
			++cnt, n /= i;
		ans = (ans * get(i, cnt)) % MOD;
	}
	if (n != 1)
		ans = (ans * get(n, 1)) % MOD;
	cout << ans << "\n";
	return 0;
}