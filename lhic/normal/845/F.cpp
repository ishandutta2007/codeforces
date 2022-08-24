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
const ll MOD = 1e9 + 7;

ll dp[2][1 << 16];
ll cur[2][2][1 << 16];
ll tmp[2][2][1 << 16];

int n, m;
int a[300];

void add(ll &a, ll b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			char x;
			cin >> x;
			if (x == 'x') {
				if (n <= m) {
					a[j] ^= (1 << i);
				}
				else
					a[i] ^= (1 << j);
			}
		}
	dp[0][0] = 1;
	if (n > m)
		swap(n, m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				for (int l = 0; l < (1 << n); ++l)
					cur[j][k][l] = 0;
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < (1 << n); ++k) {
				int g = k & (~a[i]);
				add(cur[j][0][g], dp[j][k]);
				dp[j][k] = 0;
			}
		for (int x = 0; x < n; ++x) {
			if ((a[i] >> x) & 1) {
				for (int j = 0; j < 2; ++j)
					for (int k = 0; k < (1 << n); ++k)
						add(cur[j][0][k], cur[j][1][k]), cur[j][1][k] = 0;
				continue;
			}
			for (int j = 0; j < 2; ++j)
				for (int l = 0; l < 2; ++l)
					for (int k = 0; k < (1 << n); ++k)
						tmp[j][l][k] = 0;
			for (int j = 0; j < 2; ++j)
				for (int l = 0; l < 2; ++l) 
					for (int k = 0; k < (1 << n); ++k) {
						add(tmp[j][1][k | (1 << x)], cur[j][l][k]);
						if (l || ((k >> x) & 1))
							add(tmp[j][l][k], cur[j][l][k]);
						else if (j == 0) {
							add(tmp[1][l][k], cur[j][l][k]);
						}
					}
			for (int j = 0; j < 2; ++j)
				for (int l = 0; l < 2; ++l)
					for (int k = 0; k < (1 << n); ++k)
						cur[j][l][k] = tmp[j][l][k];
		}
		for (int j = 0; j < 2; ++j)
			for (int l = 0; l < 2; ++l)
				for (int k = 0; k < (1 << n); ++k)
					add(dp[j][k], cur[j][l][k]);
	}
	ll ans = 0;
	for (int j = 0; j < 2; ++j)
		for (int k = 0; k < (1 << n); ++k)
			add(ans, dp[j][k]);
	cout << ans << "\n";
	return 0;
}