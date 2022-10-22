#include <bits/stdc++.h>
using namespace std;

const int Maxn = 705;

int n;
int a[Maxn];
bool G[Maxn][Maxn];
bool dp[Maxn][Maxn][2];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < i; j++) if (gcd(a[j], a[i]) > 1)
			G[i][j] = G[j][i] = true;
	}
	for (int i = 0; i < n; i++) {
		dp[i][i][0] = i == 0 || G[i - 1][i];
		dp[i][i][1] = i == n - 1 || G[i][i + 1];
	}
	for (int l = 1; l <= n; l++)
		for (int i = 0; i + l < n; i++) {
			int j = i + l;
			for (int k = i; k <= j && !dp[i][j][0]; k++)
				if (i == 0 || G[i - 1][k])
					dp[i][j][0] = (k == i || dp[i][k - 1][1]) && (k == j || dp[k + 1][j][0]);
			for (int k = i; k <= j && !dp[i][j][1]; k++)
				if (j == n - 1 || G[k][j + 1])
					dp[i][j][1] = (k == i || dp[i][k - 1][1]) && (k == j || dp[k + 1][j][0]);
		}
	printf("%s\n", dp[0][n - 1][0]? "Yes": "No");
	return 0;
}