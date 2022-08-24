#ifndef BZ
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

int n, k;
int cnk[5010][5010];
ll dp[5010];



int main() {
	cin >> n >> k;
	for (int i = 0; i <= k; ++i)
		for (int j = 0; j <= k; ++j) {
			if (i == j || j == 0)
				cnk[i][j] = 1;
			else if (j > i)
				cnk[i][j] = 0;
			else
				cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % MOD;
		}

	dp[1] = 1;
	for (int i = 2; i <= k; ++i) {
		dp[i] = pw(i, k);
		for (int j = 1; j < i; ++j)
			dp[i] = (dp[i] - cnk[i][j] * dp[j] % MOD + MOD) % MOD;
	}
	ll ans = 0;
	ll cc = 1;
	for (int i = 1; i <= k && i <= n; ++i) {
		cc = (cc * (n - i + 1) % MOD * pw(i, MOD - 2)) % MOD;
		ans = (ans + dp[i] * cc % MOD * pw(2, n - i)) % MOD;
	}
	cout << ans << "\n";
	return 0;
}