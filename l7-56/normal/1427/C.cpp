#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 1e5 + 10;
int dp[maxn],mxd = -2e9,mxi,x[maxn],y[maxn],t[maxn],n,r,ans;

int main() {
	// freopen(".in", "r", stdin), freopen(".out", "w", stdout);
	scanf("%d%d", &r, &n);
	x[0] = 1, y[0] = 1;
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &t[i], &x[i], &y[i]);
		while(t[i] - t[mxi] >= r * 2) mxd = max(mxd, dp[mxi++]);
		dp[i] = mxd + 1;
		for(int j = mxi; j < i; ++j)
			if(t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j])) dp[i] = max(dp[i], dp[j] + 1);
		ans = max(dp[i], ans);
	}
	printf("%d", ans);
	// fclose(stdin), fclose(stdout);
	return 0;
}