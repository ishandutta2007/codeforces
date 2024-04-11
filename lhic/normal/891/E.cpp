#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

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

const int MAXN = 5100;

void add(ll &a, ll b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
}

ll a[MAXN];
ll dp[MAXN];
ll dp2[MAXN];
int n;
ll k;

ll cc(ll k, int l) {
	return pw(l, k);
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i + 1; ++j)
			dp2[j] = 0;
		for (int j = 0; j <= i; ++j)
			add(dp2[j], dp[j]), add(dp2[j + 1], (dp[j] * a[i]) % MOD);
		for (int j = 0; j <= i + 1; ++j)
			dp[j] = dp2[j];
	}
	ll ans = 0;
	for (int l = 1; l <= n && l <= k; ++l) {
		ll cur = dp[n - l];
		if (l % 2 == 0)
			cur = (MOD - cur) % MOD;
		for (ll j = k; j > k - l; --j)
			cur = (cur * j) % MOD;
		cur = (cur * cc(k - l, n)) % MOD;
		ans = (ans + cur) % MOD;
	}
	ll q = pw(n, k);
	q = pw(q, MOD - 2);
	ans = (ans * q) % MOD;
	cout << ans << "\n";
	return 0;
}