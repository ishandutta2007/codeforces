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


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int n, k;
ll a[100];
int dp[60][60];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	ll ans = 0;
	for (int it = 59; it >= 0; --it) {
		ll cur = ans + (1ll << it);
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= k; ++j)
				dp[i][j] = 0;
		dp[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				if (dp[i][j]) {
					ll sum = 0;
					for (int l = i; l < n; ++l) {
						sum += a[l];
						if ((sum & cur) == cur)
							dp[l + 1][j + 1] = 1;
					}
				}
			}
		}
		if (dp[n][k])
			ans = cur;
	}
	cout << ans << "\n";
	return 0;
}