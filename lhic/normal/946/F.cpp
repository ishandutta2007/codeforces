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

const int X = 105;
const int N = 105;

ll dp[X][N][N][4];

int n, x;
string s;

ll pwl[N];

void add(ll &a, ll b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> x;
	cin >> s;
	pwl[0] = pwl[1] = 1;
	for (int i = 2; i <= x; ++i)
		pwl[i] = (pwl[i - 1] + pwl[i - 2]) % (MOD - 1);
	for (int i = 0; i <= x; ++i) {
		pwl[i] = pw(2, pwl[i]);
	}
	for (int i = 0; i <= x; ++i) {
		for (int l = 0; l < s.size(); ++l)
			for (int r = l + 1; r <= s.size(); ++r) {
				if (i <= 1) {
					if (r - l == 1 && s[l] == '0' + i)
						for (int k = 0; k < 4; ++k)
							dp[i][l][r][k] = 1;
				}
				else {
					add(dp[i][l][r][0], dp[i - 1][l][r][0]);
					add(dp[i][l][r][0], dp[i - 2][l][r][0]);
					for (int d = 1; d < r - l; ++d) {
						add(dp[i][l][r][0], dp[i - 1][l][l + d][0] * dp[i - 2][l + d][r][0] % MOD);
					}
					add(dp[i][l][r][1], dp[i - 1][l][r][1]);
					add(dp[i][l][r][1], dp[i - 2][l][r][1] * pwl[i - 1] % MOD);
					for (int d = 1; d < r - l; ++d) {
						add(dp[i][l][r][1], dp[i - 1][l][l + d][1] * dp[i - 2][l + d][r][0] % MOD);
					}
					add(dp[i][l][r][2], dp[i - 2][l][r][2]);
					add(dp[i][l][r][2], dp[i - 1][l][r][2] * pwl[i - 2] % MOD);
					for (int d = 1; d < r - l; ++d) {
						add(dp[i][l][r][2], dp[i - 1][l][l + d][0] * dp[i - 2][l + d][r][2] % MOD);
					}
					add(dp[i][l][r][3], dp[i - 1][l][r][3] * pwl[i - 2] % MOD);
					add(dp[i][l][r][3], dp[i - 2][l][r][3] * pwl[i - 1] % MOD);
					for (int d = 1; d < r - l; ++d) {
						add(dp[i][l][r][3], dp[i - 1][l][l + d][1] * dp[i - 2][l + d][r][2] % MOD);
					}
				}
			}
	}
	cout << dp[x][0][n][3] << "\n";
	return 0;
}