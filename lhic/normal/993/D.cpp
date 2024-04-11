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

int n;
const int MAXN = 60;
const ll INF = 1e18;

ll dp[MAXN][MAXN * 100];

ll dp2[MAXN][MAXN * 100];

pair<ll, ll> a[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].first;
	for (int i = 0; i < n; ++i)
		cin >> a[i].second;
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n * 100; ++j)
			dp[i][j] = INF;
	dp[0][0] = 0;
	int cur = 0;
	while (cur < n) {
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= n * 100; ++j)
				dp2[i][j] = INF;
		int now = cur;
		while (cur < n && a[cur].first == a[now].first)
			++cur;
		ll sm = 0;
		for (int i = 0; i <= cur - now; sm += a[now + i].second, ++i) {
			int x = i;
			int y = cur - now - x;
			for (int bal = y; bal <= n; ++bal) {
				for (int j = 0; j <= n * 100; ++j) {
					if (dp[bal][j] >= INF)
						continue;
					dp2[bal - y + x][j + sm] = min(dp2[bal - y + x][j + sm], dp[bal][j] + x * a[now].first);
				}
			}
		}
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= n * 100; ++j)
				dp[i][j] = dp2[i][j];
	}
	ll p = ll(1e9);
	ll q = 1;
	for (int i = 0; i <= n; ++i)
		for (int j = 1; j <= n * 100; ++j) {
			if (dp[i][j] < INF) {
				if (dp[i][j] * q < j * p) {
					p = dp[i][j];
					q = j;
				}
			}
		}
	p *= 1000;
	cout << (p + q - 1) / q << "\n";
	return 0;
}