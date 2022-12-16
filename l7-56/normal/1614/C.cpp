#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10, mod = 1e9 + 7;
int a[maxn],c[maxn];

int T,n,m,dp[maxn][2];
struct seg {
	int l,r,x;
}s[maxn];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; ++i) scanf("%d%d%d", &s[i].l, &s[i].r, &s[i].x);
		int ans = 0;
		for(int bit = 0, f = 1; bit < 30; ++bit, f = (f * 2) % mod) {
			for(int i = 1; i <= n; ++i) c[i] = 0;
			for(int i = 1; i <= m; ++i)
				if((s[i].x & (1 << bit)) == 0) c[s[i].l]++, c[s[i].r + 1]--;
			dp[0][0] = 1;
			for(int i = 1; i <= n; ++i)
				a[i] = (c[i] += c[i - 1]) ? 0 : 1,
				dp[i][0] = (dp[i - 1][0] + dp[i - 1][a[i]]) % mod,
				dp[i][1] = (dp[i - 1][1] + dp[i - 1][!a[i]]) % mod;
			ans = (ans + (ll)dp[n][1] * f % mod) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}