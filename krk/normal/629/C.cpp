#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxm = 2005;
const int mod = 1000000007;

int n, m;
char s[Maxn];
int dp[Maxm][Maxm][2];

int main()
{
	int mn = 0, cur = 0;
	scanf("%d %d", &n, &m); scanf("%s", s);
	for (int i = 0; i < m; i++) {
		cur += s[i] == '('? 1: -1;
		mn = min(mn, cur);
	}
	dp[0][0][0] = 1;
	for (int i = 0; i <= n - m; i++)
		for (int k = 0; k < 2; k++)
			for (int j = 0; j <= n - m; j++) {
				if (j < n - m) dp[i + 1][j + 1][k] = (dp[i + 1][j + 1][k] + dp[i][j][k]) % mod;
				if (j > 0) dp[i + 1][j - 1][k] = (dp[i + 1][j - 1][k] + dp[i][j][k]) % mod;
				if (k == 0 && j + mn >= 0) {
					int nj = j + cur;
					if (nj >= 0 && nj <= n - m - i)
						dp[i][nj][1] = (dp[i][nj][1] + dp[i][j][k]) % mod;
				}
			}
	printf("%d\n", dp[n - m][0][1]);
	return 0;
}