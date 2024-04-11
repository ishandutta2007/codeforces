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

const int MAXN = 310000;

const ll INF = 1e18;

int n;
ll x[MAXN];
ll y[MAXN];
ll dp[6][6][6][6];
ll dp2[6][6][6][6];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	ll ans = (*max_element(x, x + n) - *min_element(x, x + n)) * 2 + (*max_element(y, y + n) - *min_element(y, y + n)) * 2;
	for (int i = 0; i <= 3; ++i)
		for (int j = 0; j <= 3; ++j)
			for (int k = 0; k <= 3; ++k)
				for (int l = 0; l <= 3; ++l)
					dp[i][j][k][l] = -INF;
	dp[0][0][0][0] = 0;
	for (int it = 0; it < n; ++it) {
		memcpy(dp2, dp, sizeof(dp));
		for (int i = 0; i <= 3; ++i)
			for (int j = 0; j <= 3; ++j)
				for (int k = 0; k <= 3; ++k)
					for (int l = 0; l <= 3; ++l) {
						for (int x1 = 0; x1 <= 2; ++x1)
							for (int y1 = 0; y1 <= 2; ++y1)
								dp2[i + x1][j + y1][k + 2 - x1][l + 2 - y1] = max(dp2[i + x1][j + y1][k + 2 - x1][l + 2 - y1], dp[i][j][k][l] + x[it] * (2 * x1 - 2) + y[it] * (2 * y1 - 2));
					}
		memcpy(dp, dp2, sizeof(dp));
	}
	cout << dp[3][3][3][3] << " ";
	for (int i = 4; i <= n; ++i)
		cout << ans << " ";
	cout << "\n";
	return 0;
}