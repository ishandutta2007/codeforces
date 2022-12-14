#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int test, n, ans;
char s[2222], t[2222];
struct cond
{
	int w, s;
}dp[2222][2222][2], pdp[2222][2];
void add(int &x, int y)
{
	x += y;
	if (x >= mod) x -= mod;
}
void trans(cond &x, cond &y, int c)
{
	add(x.w, y.w);
	add(x.s, (1ll * y.w * c + y.s) % mod);
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		scanf("%s%s", s, t);
		for (int i = 0; i <= n + 1; i++)
		{
			for (int j = 0; j <= n + 1; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					dp[i][j][k].w = 0;
					dp[i][j][k].s = 0;
				}
			}
		}
		dp[n][n][0].w = 1;
		for (int i = n; i >= 1; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				for (int k = 0; k < 2; k++)
				pdp[j][k].s = pdp[j][k].w = 0;
			}
			for (int j = 0; j <= i; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					if (!dp[i][j][k].w && !dp[i][j][k].s) continue;
					for (int u = 0; u < 2; u++)
					{
						if (j < i)
						{
							if (u != k ^ ((i - j) & 1)) continue;
						}
						else
						{
							if (s[i - 1] == '0' + (u ^ 1)) continue;
						}
						for (int d = 0; d < 2; d++)
						{
							if (t[i - 1] == '0' + (d ^ 1)) continue;
							if (u == d)
							{
								if (j >= i - 1) trans(dp[i - 1][i - 1][0], dp[i][j][k], 0);
								else trans(dp[i - 1][j][k], dp[i][j][k], 0);
							}
							else
							{
								if (i == j) trans(pdp[i - 1][u ^ 1], dp[i][j][k], 0);
								else trans(pdp[j][k], dp[i][j][k], 0);
							}
						}
					}
				}
			}
			for (int j = i - 1; j >= 1; j--)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int h = 0; h < 2; h++)
					{
						if (s[j - 1] == '0' + (h ^ 1)) continue;
						if (k == h)
						{
							trans(pdp[j - 1][k ^ 1], pdp[j][k], 0);
						}
						else
						{
							trans(dp[i - 1][j - 1][k ^ 1], pdp[j][k], i - j);
						}
					}
				}
			}
		}
		printf("%d\n", (dp[0][0][0].s + dp[0][0][1].s) % mod);
	}
	return 0;
}