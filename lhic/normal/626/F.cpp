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
int a[210];

ll dp[2][210][1200];
int kk;

void add(ll &a, ll b) {
	if (b >= MOD)
		b %= MOD;
	a += b;
	if (a >= MOD)
		a -= MOD;
}

int main() {
	scanf("%d%d", &n, &kk);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	dp[0][0][0] = 1;
	int dd = 0;
	int dd2 = 1;
	for (int i = 1; i <= n; ++i) {
		dd ^= 1;
		dd2 ^= 1;
		for (int j = 0; j <= n; ++j)
			for (int k = 0; k <= kk; ++k) {
				dp[dd][j][k] = 0;
				if (i == 1) {
					if (j == 0)
						add(dp[dd][j][k], dp[dd2][j][k]);
					else
						add(dp[dd][j][k], dp[dd2][j - 1][k]);
				}
				else {
					int d = a[i - 1] - a[i - 2];
					if (k >= d * j)
						add(dp[dd][j][k], dp[dd2][j][k - d * j]);
					if (k >= d * (j + 1))
						add(dp[dd][j][k], dp[dd2][j + 1][k - d * (j + 1)]);
					if (j > 0) {
						if (k >= d * (j - 1))
							add(dp[dd][j][k], j * dp[dd2][j - 1][k - d * (j - 1)]);
						if (k >= d * j)
							add(dp[dd][j][k], j * dp[dd2][j][k - d * j]);
					}
				}
			}
	}
	ll ans = 0;
	for (int i = 0; i <= kk; ++i)
		ans = (ans + dp[dd][0][i]) % MOD;
	cout << ans << "\n";
	
	return 0;
}