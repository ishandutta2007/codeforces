#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 2011

int n, m;
char a[N], b[N];
int dp[N][N];
int main() {
	scanf("%s%s", a + 1, b + 1);
	memset(dp, 0x3f, sizeof dp);
	n = (int)strlen(a + 1);
	m = (int)strlen(b + 1);
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
		for (int j = 0; j < m; j++) {
			dp[i][j] = min(dp[i][j], j);
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (a[i + 1] != b[j + 1]));
			dp[i][m] = min(dp[i][m], dp[i][j] + (m - j));
		}
	}
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= n; i++) ans = min(ans, dp[i][m]);
	printf("%d\n", ans);
}