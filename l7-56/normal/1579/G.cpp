#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 1e4 + 10, maxd = 3010, inf = 2e9;
int a[maxn],n,T,ans,dp[maxn][maxd];

int main() {
	// freopen(".in", "r", stdin), freopen(".out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		int mx = 0;
		ans = 2e9;
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), mx = max(mx, a[i]);
		mx *= 2;
		vector <vector <int> > dp(n + 2, vector <int> (mx + 1010, inf));
		dp[1][0] = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j <= mx; ++j)
				dp[i + 1][j + a[i]] = min(dp[i + 1][j + a[i]], max(dp[i][j] - a[i], 0)),
				dp[i + 1][max(j - a[i], 0)] = min(dp[i + 1][max(j - a[i], 0)], dp[i][j] + a[i]);
		for(int j = 0; j <= mx; ++j) ans = min(ans, dp[n + 1][j] + j);
		printf("%d\n", ans);
	}
	// fclose(stdin), fclose(stdout);
	return 0;
}