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

const ll INF = 1e9 + 100;

int dp[2000];

ll n;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < 1000; ++i)
		dp[i] = INF;
	dp[0] = 0;
	for (int i = 0; i < 1000; ++i) {
		dp[i + 4] = min(dp[i + 4], dp[i] + 1);
		dp[i + 49] = min(dp[i + 49], dp[i] + 1);
		dp[i + 9] = min(dp[i + 9], dp[i] + 1);
	}
	ll ans = 0;
	for (int i = 0; i < 49; ++i) {
		if (dp[i] <= n) {
			ans += n - dp[i] + 1;
		}
	}
	for (int i = 49; i < 98; ++i) {
		ll pr = dp[i - 49];
		ll now = dp[i];
		if (now < pr + 1 && now <= n) {
			if (pr <= n) {
				ans += pr + 1 - now;
			}
			else {
				ans += n - now + 1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}