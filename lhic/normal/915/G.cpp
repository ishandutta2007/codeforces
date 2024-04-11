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

const int MAXN = 2e6 + 100;

ll pww[MAXN];
ll dp[MAXN];

int n, k;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; ++i)
		pww[i] = pw(i, n);
	ll ans = 0;
	ll sum = 0;
	for (int i = 1; i <= k; ++i) {
		dp[i] += pww[i] - pww[i - 1];
		dp[i] %= MOD;
		if (dp[i] < 0)
			dp[i] += MOD;
		sum = (sum + dp[i]) % MOD;
		ans = (ans + (sum ^ i)) % MOD;
		for (int j = i + i; j <= k; j += i)
			dp[j] -= dp[i];
	}
	cout << ans << "\n";
	return 0;
}