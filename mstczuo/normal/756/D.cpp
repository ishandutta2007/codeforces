# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
const int mod = 1000000007;
const int maxn = 100010;

int n, m;
char a[maxn];
int nxt[maxn][26];
int dp[2][maxn];

int main() {
	scanf("%d", &n);
	scanf("%s", a);
	m = unique(a, a + n) - a;
	for(int j = 0; j < 26; ++j) nxt[m][j] = m;
	for(int i = m - 1; i >= 0; --i) {
		for(int j = 0; j < 26; ++j) nxt[i][j] = nxt[i + 1][j];
		nxt[i][a[i] - 'a'] = i;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		memset(dp[i & 1], 0, sizeof(dp[0]));
		int p = i & 1;
		for(int j = 0; j < m; ++j) if(dp[p ^ 1][j]) {
			int val = dp[p ^ 1][j];
			for(int c = 0; c < 26; ++c) if(nxt[j][c] < m) 
				(dp[i & 1][nxt[j][c]] += val) %= mod;
		}
	}
	int ans = 0;
	for(int j = 0; j < m; ++j) (ans += dp[n & 1][j]) %= mod;
	printf("%d\n", ans);
}