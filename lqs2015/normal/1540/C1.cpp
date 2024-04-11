#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, c[111], b[111], q, x[111111], dp[111][11111], sum[111], all, ans;
void add(int &x, int y)
{
	x += y;
	if (x >= mod) x -= mod; 
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i < n; i++) scanf("%d", &b[i]);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) scanf("%d", &x[i]);
	for (int i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + b[i];
	}
	for (int i = 1; i < n; i++) sum[i] += sum[i - 1];
	for (int i = 1; i <= n; i++) all += c[i];
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = sum[i - 1] + i * x[1]; j <= all; j++)
		{
			for (int k = 0; k <= min(c[i], j); k++)
			{
				add(dp[i][j], dp[i - 1][j - k]);
			}
		}
	}
	for (int i = 0; i <= all; i++) add(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}