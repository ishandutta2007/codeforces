#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 210, mod = 1e9 + 7;
int n,m,dp[maxn][maxn][maxn],to[maxn][2];
char s[maxn];

int num(char ch) { return ch == ')'; }
#define f(a, b) ((a) = ((a) + (b)) % mod)

int main() {
	scanf("%d%s", &n, s + 1);
	m = strlen(s + 1);
	to[0][s[1] == ')'] = 1;
	for (int i = 1; i < m; ++i) {
		for (int p = 0; p < 2; ++p) {
			if ((s[i + 1] == ')') == p) to[i][p] = i + 1;
			else {
				int res = i;
				for (; res; --res) {
					if ((s[res] == ')') != p) continue;
					bool flag = 1;
					for (int j1 = 1, j2 = i - res + 2; j2 <= i && flag; ++j1, ++j2) flag &= (s[j1] == s[j2]);
					if (flag) break;
				}
				to[i][p] = res;
			}
		}
	}
	to[m][0] = to[m][1] = m;
	dp[0][0][0] = 1;
	for (int i = 0; i < n + n; ++i)
		for (int j = 0; j <= n; ++j)
			for (int k = 0; k <= m; ++k) {
				f(dp[i + 1][j + 1][to[k][0]], dp[i][j][k]);
				if (j) f(dp[i + 1][j - 1][to[k][1]], dp[i][j][k]);
			}
	printf("%d\n", dp[n + n][0][m]);
	return 0;
}