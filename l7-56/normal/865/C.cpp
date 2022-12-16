#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 60, maxt = 5010;
ld dp[maxn][maxt];
/*
dp[i][t] : it
mid
dp[i][j] = mid (jm + 100j + a[i] > m) 
dp[i][j] = mid
dp[i][j] = dp[i + 1][j + a[i]] * p[i] / 100 + dp[i + 1][j + b[i]] * (1 - p[i] / 100)
dp[1][0]midmidmid 
*/
int n,m,a[maxn],b[maxn],p[maxn];

bool check(ld mid) {
	for(int i = 1; i <= n + 1; ++i)
		for(int j = m + 1; j <= 5000; ++j)
			dp[i][j] = mid;
	for(int i = n; i >= 1; --i)
		for(int j = 0; j <= m; ++j)
			dp[i][j] = min(mid, (dp[i + 1][j + a[i]] + a[i]) * p[i] / 100 + (dp[i + 1][j + b[i]] + b[i]) * (100 - p[i]) / 100);
	return dp[1][0] >= mid;
}

int main() {
	// freopen(".in", "r", stdin), freopen(".out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d%d%d", &a[i], &b[i], &p[i]);
	ld l = 0, r = 1e10, mid, ans = -1;
	for(int i = 1; i <= 200; ++i) {
		mid = (l + r) / 2;
		if(check(mid)) ans = l = mid;
		else r = mid;
	}
	printf("%.9Lf", ans);
	// fclose(stdin), fclose(stdout);
	return 0;
}