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

const int MAXN = 120000;
const ll MOD = 998244353;

int n;

int a[MAXN];
ll dp[2][210];
ll dp2[2][210];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	if (a[0] == -1) {
		for (int i = 1; i <= 200; ++i)
			dp[0][i] = 1;
	}
	else
		dp[0][a[0]] = 1;
	for (int i = 1; i < n; ++i) {
		memset(dp2, 0, sizeof(dp2));
		ll sum = 0;
		for (int j = 1; j <= 200; ++j) {
			dp2[0][j] = sum;
			dp2[1][j] = (dp[0][j] + dp[1][j]) % MOD;
			sum = (sum + dp[0][j] + dp[1][j]) % MOD;
		}
		sum = 0;
		for (int j = 200; j >= 1; --j) {
			dp2[1][j] = (dp2[1][j] + sum) % MOD;
			sum = (sum + dp[1][j]) % MOD;
		}
		if (a[i] != -1) {
			for (int j = 1; j <= 200; ++j)
				if (j != a[i])
					dp2[0][j] = dp2[1][j] = 0;
		}
		memcpy(dp, dp2, sizeof(dp));
	}
	ll ans = 0;
	for (int i = 1; i <= 200; ++i)
		ans = (ans + dp[1][i]) % MOD;
	cout << ans << "\n";
	return 0;
}