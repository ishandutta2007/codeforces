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

const ll INF = 1e18;

int n;
const int MAXN = 5100;

ll a[MAXN];
ll dp[3][MAXN];
ll dp2[3][MAXN];

void upd(ll &a, ll b) {
	a = min(a, b);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = INF;
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j <= n; ++j)
				dp2[i][j] = INF;
		for (int j = 0; j <= n; ++j) {
			if (dp[0][j] != INF) {
				upd(dp2[1][j + 1], dp[0][j] + max(0ll, a[i - 1] - (a[i] - 1)));
				upd(dp2[0][j], dp[0][j]);
			}
			if (dp[1][j] != INF) {
				upd(dp2[0][j], dp[1][j] + max(0ll, a[i] - (a[i - 1] - 1)));
				upd(dp2[2][j], dp[1][j] + max(0ll, a[i] - min((a[i - 1] - 1), (a[i + 1] - 1))));
			}
			if (dp[2][j] != INF) {
				upd(dp2[1][j + 1], dp[2][j]);
			}
		}
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j <= n; ++j)
				dp[i][j] = dp2[i][j];
	}
	for (int i = 1; i <= (n + 1) / 2; ++i) {
		ll ans = min({dp[0][i], dp[1][i], dp[2][i]});
		cout << ans << "\n";
	}
	return 0;
}