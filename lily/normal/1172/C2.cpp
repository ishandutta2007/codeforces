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

#define N 200005
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
LL dp[M][M];

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) {
		read(b[i]);
		if (a[i]) goodw += b[i];
		else 	  badw  += b[i];
	}
	dp[0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= min(badw, i); j++) if (dp[i][j]) {
			const int gt = i - j, bt = j;
			(dp[i + 1][j] += dp[i][j] * frac(goodw + gt, goodw + badw + gt - bt)) %= MOD;
			(dp[i + 1][j + 1] += dp[i][j] * frac(badw - bt, goodw + badw + gt - bt)) %= MOD;
		}
	}


	LL gbase = 0, bbase = 0;
	for (int i = 0; i <= m; i++) {
		(gbase += dp[m][m - i] * i) %= MOD;
		(bbase += dp[m][i] * i) %= MOD;
	}
	(gbase *= inv(goodw)) %= MOD;
	(bbase *= inv(badw)) %= MOD;
	
	//gbase++; bbase++;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			printf("%lld\n", b[i] * (1 + gbase) % MOD);
		}
		else {
			printf("%lld\n", b[i] * (1 + MOD -bbase) % MOD);
		}
	}
}