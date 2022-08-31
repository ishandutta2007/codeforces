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

int go[5100];

int a[5100];
int dp[5100][5100];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		int len = n - i;
		for (int j = 0; i + j < n; ++j)
			go[j] = a[i + j];
		int mx = len - 1;
		int cnt = 0;
		while (mx)
			mx >>= 1, ++cnt;
		for (int j = 0; j < cnt; ++j)
			for (int k = 0; k + (1 << j) < len; ++k) {
				if (!((k >> j) & 1))
					go[k ^ (1 << j)] ^= go[k];
			}
		for (int j = 0; j < len; ++j) {
			dp[i][i + j] = go[j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n - 1; ++j)
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
	}
	for (int j = 0; j < n; ++j)
		for (int i = j; i > 0; --i) {
			dp[i - 1][j] = max(dp[i - 1][j], dp[i][j]);
		}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--r;
		--l;
		cout << dp[l][r] << "\n";
	}
	return 0;
}