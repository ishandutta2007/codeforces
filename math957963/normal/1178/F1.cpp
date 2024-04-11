#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 998244353
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 600
long long a[N];
long long dp[N][N];
long long ll[N];
long long rr[N];

void solve(long long lx, long long rx) {
	if (rx - lx <0) {
		dp[lx][rx] = 0;
		return;
	}
	if (rx - lx < 2) {
		dp[lx][rx] = 1;
		return;
	}
	long long k, x, y, z;
	x = MOD;
	for (long long i = lx; i < rx; i++) {
		if (a[i] < x) {
			x = a[i];
			k = i;
		}
	}
	x = 0;
	for (long long i = ll[k]; i <= k; i++) {
		if(dp[lx][i]<0)solve(lx, i);
		if (dp[i][k] < 0)solve(i, k);
		z = (dp[lx][i] * dp[i][k]) % MOD;
		x = (x + z) % MOD;
	}
	y = 0;
	for (long long i = k+1; i <= rr[k]; i++) {
		if (dp[k+1][i] < 0)solve(k+1, i);
		if (dp[i][rx] < 0)solve(i, rx);
		z = (dp[k+1][i] * dp[i][rx]) % MOD;
		y = (y + z) % MOD;
	}
	dp[lx][rx] = (x*y) % MOD;
	return;
}




int main() {
	long long n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d %I64d", &n, &k);
	f(i, n) {
		scanf("%I64d", &a[i]);
	}
	f(i, N) {
		f(j, N)dp[i][j] = -1;
	}
	f(i, n) {
		rr[i] = n;
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				rr[i] = j;
				break;
			}
		}
	}
	f(i, n) {
		ll[i] = 0;
		for (int j = i - 1; j >=0; j--) {
			if (a[i] > a[j]) {
				ll[i] = j + 1;
				break;
			}
		}
	}

	solve(0,n);

	printf("%I64d\n", dp[0][n]);


	return 0;
}