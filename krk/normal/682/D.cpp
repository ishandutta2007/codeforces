#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int Maxk = 12;
const int Inf = 1000000000;

int n, m, k;
int dp[Maxn][Maxn][Maxk][2];
string a, b;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	fill((int*)dp, (int*)dp + Maxn * Maxn * Maxk * 2, -Inf);
	cin >> a >> b;
	dp[0][0][0][0] = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int l = 0; l <= k; l++) {
				int nl = l == k? l: l + 1;
				dp[i][j][nl][0] = max(dp[i][j][nl][0], dp[i][j][l][1]);
				if (l < k && i < n && j < m && a[i] == b[j]) 
					dp[i + 1][j + 1][l][1] = max(dp[i + 1][j + 1][l][1], dp[i][j][l][1] + 1); 
				if (i < n) dp[i + 1][j][l][0] = max(dp[i + 1][j][l][0], dp[i][j][l][0]);
				if (j < m) dp[i][j + 1][l][0] = max(dp[i][j + 1][l][0], dp[i][j][l][0]);
				if (l < k && i < n && j < m && a[i] == b[j])
					dp[i + 1][j + 1][l][1] = max(dp[i + 1][j + 1][l][1], dp[i][j][l][0] + 1);
			}
	printf("%d\n", dp[n][m][k][0]);
	return 0;
}