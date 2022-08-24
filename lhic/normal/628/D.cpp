#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const ll MOD = 1000000007;
int n;
int m;

ll dp[2100];
ll dp2[2100];
int cg;
int d;
char as[2100];
char bs[2100];

void solve(char *s) {
	for (int i = 0; i < m; ++i)
		dp[i] = 0;
	int fl = 0;
	int sm = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			memset(dp2, 0, sizeof(dp2[0]) * m);
			for (int j = 1; j < 10; ++j) {
				if (j == d)
					continue;
				for (int k = 0; k < m; ++k) {
					int g = k * 10 + j;
					g %= m;
					dp2[g] += dp[k];
					if (dp2[g] >= MOD)
						dp2[g] -= MOD;
				}
				if (!fl && j < s[i] - '0') {
					int g = (sm * 10 + j) % m;
					++dp2[g];
					if (dp2[g] == MOD)
						dp2[g] -= MOD;
				}
			}
			if (!fl && (s[i] - '0') != d) {
				sm = (sm * 10 + s[i] - '0') % m;
			}
			else {
				fl = 1;
			}
			memcpy(dp, dp2, sizeof(dp[0]) * m);
		}
		else if (i & 1) {
			if (!fl && d > s[i] - '0')
				fl = 1;
			memset(dp2, 0, sizeof(dp2[0]) * m);
			for (int j = 0; j < m; ++j)
				dp2[(j * 10 + d) % m] += dp[j];
			for (int j = 0; j < m; ++j)
				dp2[j] %= MOD;
			memcpy(dp, dp2, sizeof(dp[0]) * m);
			sm = sm * 10 + d;
			sm %= m;
			if (!fl) {
				if (d < s[i] - '0') {
					fl = 1;
					++dp[sm];
					if (dp[sm] == MOD)
						dp[sm] = 0;
				}
			}
		}
		else {
			memset(dp2, 0, sizeof(dp2[0]) * m);
			for (int j = 0; j < 10; ++j) {
				if (j == d)
					continue;
				for (int k = 0; k < m; ++k) {
					int g = k * 10 + j;
					g %= m;
					dp2[g] += dp[k];
					if (dp2[g] >= MOD)
						dp2[g] -= MOD;
				}
				if (!fl && j < s[i] - '0') {
					int g = (sm * 10 + j) % m;
					++dp2[g];
					if (dp2[g] == MOD)
						dp2[g] -= MOD;
				}
			}
			if (!fl && (s[i] - '0') != d) {
				sm = (sm * 10 + s[i] - '0') % m;
			}
			else {
				fl = 1;
			}
			memcpy(dp, dp2, sizeof(dp[0]) * m);
		}
	}
	cg = 1;
	if (!fl)
		cg = sm;
}

int main() {
	scanf("%d%d", &m, &d);
	scanf(" %s", as);
	scanf(" %s", bs);
	n = strlen(as);
	solve(as);
	ll ans = 0;
	ans -= dp[0];
	solve(bs);
	ans += dp[0];
	if (cg == 0)
		++ans;
	ans += MOD * 2;
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}