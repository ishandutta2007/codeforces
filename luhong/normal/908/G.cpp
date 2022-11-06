#include <cstdio>
#include <iostream>
#include <cstring>
#define MN 710
#define mod 1000000007

int w[11][MN], inv[MN], fac[MN];
int f[11][MN], g[11][MN];
char s[MN];
int cnt[MN];

int main()
{
	scanf("%s", s + 1); int n = strlen(s + 1);
	for(int d = 1; d <= 9; d++)
		for(int i = 1; i <= n; i++)
			w[d][i] = (w[d][i - 1] * 10ll + d) % mod;
	w[10][0] = 1; for(int i = 1; i <= n; i++) w[10][i] = w[10][i - 1] * 10ll % mod;
	inv[0] = inv[1] = fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	for(int i = 2; i <= n; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i <= n; i++) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
	g[0][0] = 1;
	for(int i = 1; i <= 10; i++)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= j; k++)
				g[i][j] = (g[i][j] + 1ll * g[i - 1][j - k] * inv[k]) % mod;
	for(int i = 1; i < 10; i++)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= j; k++)
				f[i][j] = (f[i][j] + 1ll * w[i][k] * w[10][j - k] % mod * inv[k] % mod * g[9 - i][j - k]) % mod;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < s[i] - '0' + (i == n ? 1 : 0); j++)
		{
			cnt[j]++; int S = 0;
			for(int k = 9; k >= 0; k--)
			{
				for(int l = 0; l <= n - i; l++)
					ans = (ans + (f[k][l] + 1ll * w[k][cnt[k]] * w[10][l] % mod * g[10 - k][l] % mod) * w[10][S] % mod * g[k][n - i - l] % mod * fac[n - i]) % mod;
				S += cnt[k];
			}
			cnt[j]--;
		}
		cnt[s[i] - '0']++;
	}
	printf("%d\n", ans);
}