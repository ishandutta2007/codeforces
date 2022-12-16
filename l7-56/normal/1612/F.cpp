#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 2e5 + 10;
int n,m,Q;
set <int> s[maxn];

int dp[maxn][2];
void init(int p) {
	for(int i = 1; i <= n; ++i) dp[i][p] = 0;
}

int main() {
	scanf("%d%d%d", &n, &m, &Q);
	for(int x,y; Q--; ) {
		scanf("%d%d", &x, &y);
		s[x].insert(y);
	}
	int ans = INT_MAX;
	dp[1][0] = 1;
	for(int i = 0, p = 0; i <= 30; p ^= 1, ++i) {
		if(i >= ans) break;
		if(dp[n][p]) {
			int rst = 0;
			for(int nw = dp[n][p]; nw < m; nw = min(m, n + nw + (int)s[n].count(nw))) ++rst;
			ans = min(ans, rst + i);
		}
		for(int j = n; j >= 1; --j)
			if(dp[j][p] == m) {
				int rst = 0;
				for(int nw = j; nw < n; nw = min(n, m + nw + (int)s[nw].count(m))) ++rst;
				ans = min(ans, rst + i);
				break;
			}
		init(p ^ 1);
		for(int j = 1; j <= n; ++j)
			if(dp[j][p]) {
				int val = j + dp[j][p] + s[j].count(dp[j][p]);
				dp[j][p ^ 1] = max(dp[j][p ^ 1], min(val, m));
				dp[min(val, n)][p ^ 1] = max(dp[min(val, n)][p ^ 1], dp[j][p]);
			}
	}
	printf("%d\n", ans);
	return 0;
}