#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007

int f[5010][5010], g[5010][5010], lcp[5010][5010];
int s1[5010][5010], s2[5010][5010];
bool used[5010];
char c[5010];

int main()
{
	scanf("%s", c); int n = strlen(c); c[n + 1] = '@';
	for(int i = n; i >= 1; i--) c[i] = c[i - 1];
	for(int i = 1; i <= n; i++) f[1][i] = 1, g[1][i] = 1;
	for(int i = n; i >= 1; i--)
		for(int j = i - 1; j >= 1; j--)
		{
			if(c[i] == c[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
			else lcp[i][j] = 0;
		}
	for(int i = 2; i <= n; i++)
	{
		for(int j = 2; j <= i; j++)
		{
			g[j][i] = 1e9;
			if(c[j] == '0') continue;
			if(!used[j - 1])
			{
				used[j - 1] = 1;
				for(int k = 1; j - k >= 1; k++)
				{
					s1[j - 1][k] = f[j - k][j - 1];
					s2[j - 1][k] = g[j - k][j - 1];
				}
				s2[j - 1][0] = 1e9;
				for(int k = 1; j - k >= 1; k++)
					s1[j - 1][k] = (s1[j - 1][k] + s1[j - 1][k - 1]) % mod,
					s2[j - 1][k] = std::min(s2[j - 1][k], s2[j - 1][k - 1]);
			}
			int len = i - j + 1;
			f[j][i] = s1[j - 1][std::min(j - 1, len - 1)];
			g[j][i] = s2[j - 1][std::min(j - 1, len - 1)] + 1;
			if(j - len >= 1)
			{
				int Lcp = lcp[j][j - len];
				if(Lcp >= len || c[j + Lcp] > c[j - len + Lcp]) f[j][i] = (f[j][i] + f[j - len][j - 1]) % mod,
																g[j][i] = std::min(g[j][i], g[j - len][j - 1] + 1);
			}
		}
	}
	int ans = 0, ans2 = 1000000000;
	for(int i = 1; i <= n; i++)
	{
		ans = (ans + f[i][n]) % mod;
	}
	for(int i = std::max(1, n - 15); i <= n; i++)
	{
		if(g[i][n] <= 5000)
		{
			int res = 0;
			for(int j = i; j <= n; j++)
			{
				res = res * 2 + c[j] - '0';
			}
			ans2 = std::min(ans2, res + g[i][n]);
		}
	}
	if(ans2 == 1000000000)
		for(int i = n - 16; i >= 1; i--)
		{
			if(g[i][n] <= 5000)
			{
				int res = 0;
				for(int j = i; j <= n; j++)
				{
					res = (res * 2 + c[j] - '0') % mod;
				}
				ans2 = (res + g[i][n]) % mod;
				break;
			}
		}
	printf("%d\n%d", ans, ans2);
	return 0;
}