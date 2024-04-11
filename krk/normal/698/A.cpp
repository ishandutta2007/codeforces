#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];
int dp[Maxn][2];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < 2; j++) {
			if (a[i] & 1 << j)
				dp[i][j] = max(dp[i][j], dp[i + 1][1 - j] + 1);
			dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i + 1][1 - j]));
		}
	printf("%d\n", n - max(dp[0][0], dp[0][1]));
	return 0;
}