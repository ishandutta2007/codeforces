#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mp(a, b) make_pair
#define x first
#define y second
#define read(x) scanf("%d", &x)
#define readl(x) scanf("%lld", &x)
#define readd(x) scanf("%lf", &x)

#define N 20005
#define M 3005
#define MOD 998244353

LL power(LL x, LL y) {
	LL ret = 1;
	for ( ; y; y >>= 1) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}

#define inv(x) power(x, MOD - 2)

LL frac(LL x, LL y) {
	return x * inv(y) % MOD;
}

int n, m;
int a[N], b[N], goodw, badw;
LL dp[55][55][55];

void solve(int x) {
	memset(dp, 0, sizeof dp);
	dp[0][0][0] = 1;
	if (a[x]) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j <= min(badw, i); j++) {
				const int gt = i - j, bt = j;
				const LL goodpos =  frac(goodw + gt, goodw + badw + gt - bt);
				const LL badpos = 	frac(badw - bt, goodw + badw + gt - bt);
				for (int k = 0; k <= gt; k++) if (dp[i][j][k]) {
					(dp[i + 1][j][k] += dp[i][j][k] * goodpos % MOD * frac(goodw + gt - (b[x] + k), goodw + gt)) %= MOD;
					(dp[i + 1][j][k + 1] += dp[i][j][k] * goodpos % MOD * frac(b[x] + k, goodw + gt)) %= MOD;
					(dp[i + 1][j + 1][k] += dp[i][j][k] * badpos) %= MOD;
				}
			}
		}
	}
	else {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j <= min(badw, i); j++) {
				const int gt = i - j, bt = j;
				const LL goodpos =  frac(goodw + gt, goodw + badw + gt - bt);
				const LL badpos = 	frac(badw - bt, goodw + badw + gt - bt);
				for (int k = 0; k <= bt; k++) if (dp[i][j][k]) {
					(dp[i + 1][j + 1][k] += dp[i][j][k] * badpos % MOD * frac(badw - bt - (b[x] - k), badw - bt)) %= MOD;
					(dp[i + 1][j + 1][k + 1] += dp[i][j][k] * badpos % MOD * frac((b[x] - k), badw - bt)) %= MOD;
					(dp[i + 1][j][k] += dp[i][j][k] * goodpos) %= MOD;
				}
			}
		}
	}
	LL ans = 0;
	for (int j = 0; j <= m; j++) {
		for (int k = 0; k <= m; k++) if (dp[m][j][k]){
			(ans += dp[m][j][k] * k) %= MOD;
		}
	}
	printf("%lld\n", (MOD + (a[x] ? ans : -ans) + b[x]) % MOD);
}


int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) {
		read(b[i]);
		if (a[i]) goodw += b[i];
		else 	  badw  += b[i];
	}
/*	dp[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		dp[i][0] = dp[i - 1][0] * frac(goodw + i - 1, goodw + i - 1 + badw) % MOD;
		for (int j = 0; j <= min(badw, i); j++) {
			const int gt = i - 1 - j, bt = j;
			(dp[i][j] = dp[i - 1][j] * frac(goodw + gt, goodw + badw + gt - bt)
				+	   dp[i - 1][j - 1] * frac(badw - bt, goodw + badw + gt - bt)) %= MOD;
			}
		}
	}
*/
	for (int i = 1; i <= n; i++) solve(i);
}