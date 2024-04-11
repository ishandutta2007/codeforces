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

const int MAXN = 1e6 + 10;

int cc[MAXN];
int n, m;

const int INF = 1e9;

int dp[4][6];
int dp2[4][6];

void upd(int &a, int b) {
	a = max(a, b);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		++cc[x];
	}
	for (int i = 0; i <= 3; ++i)
		for (int j = 0; j <= 5; ++j)
			dp[i][j] = -INF;
	dp[0][0] = 0;
	int ans = 0;
	for (int it = 0; it < m; ++it) {
		for (int i = 0; i <= 3; ++i)
			for (int j = 0; j <= 5; ++j)
				dp2[i][j] = -INF;
		int x = cc[it];
		while (x > 7)
			x -= 3, ++ans;
		for (int i = 0; i <= 3; ++i)
			for (int j = 0; j <= 5; ++j) {
				int a = i;
				int b = j;
				int c = x;
				int go1 = min({a, b, c});
				a -= go1, b -= go1, c -= go1;
				upd(dp2[min(b, 3)][min(c, 5)], dp[i][j] + go1);
				if (c >= 3)
					upd(dp2[min(b, 3)][min(c - 3, 5)], dp[i][j] + go1 + 1);
				if (c >= 6)
					upd(dp2[min(b, 3)][min(c - 6, 5)], dp[i][j] + go1 + 2);
			}
		memcpy(dp, dp2, sizeof(dp));
	}
	int ans2 = 0;
	for (int i = 0; i <= 3; ++i)
		for (int j = 0; j <= 5; ++j)
			ans2 = max(ans2, ans + dp[i][j]);
	cout << ans2 << "\n";
	return 0;
}