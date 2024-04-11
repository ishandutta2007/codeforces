#include <iostream>
#include <cstdio>
#define MN 201000
#define mod 998244353

int n, m, s0, s1, e0, e1;
int a[MN], t[MN];
int f[3010][3010];
int fac[6010], inv[6010];

int qpow(int x, int p)
{
	int ans = 1;
	for(; p; p >>= 1, x = 1ll * x * x % mod) if(p & 1) ans = 1ll * ans * x % mod;
	return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &t[i]);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(!t[i]) s0 += a[i];
		else s1 += a[i];
	}
	fac[0] = 1; for(int i = -m; i <= m; i++) fac[i + m + 1] = 1ll * fac[i + m] * std::max(s0 + s1 + i, 1) % mod;
	inv[m + m + 1] = qpow(fac[m + m + 1], mod - 2);
	for(int i = m - 1; i >= -m; i--) inv[i + m + 1] = 1ll * inv[i + m + 2] * std::max(s0 + s1 + i + 1, 1) % mod;
	for(int i = -m; i <= m; i++) inv[i + m + 1] = 1ll * inv[i + m + 1] * fac[i + m] % mod;
	f[0][0] = 1;
	for(int i = 1; i <= m; i++)
		for(int j = 0; j <= i; j++)
		{
			int k = i - j;
			if(j < i) f[i][j] = (f[i][j] + 1ll * f[i - 1][j] * (s1 + k - 1) % mod * inv[-j + k - 1 + m + 1]) % mod;
			if(j > 0) f[i][j] = (f[i][j] + 1ll * f[i - 1][j - 1] * (s0 - (j - 1)) % mod * inv[-(j - 1) + k + m + 1]) % mod;
		}
	for(int i = 0; i <= m; i++) 
	{
		e0 = (e0 + 1ll * (s0 - i) * f[m][i]) % mod;
		e1 = (e1 + 1ll * (s1 + i) * f[m][m - i]) % mod;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!t[i]) printf("%lld\n", 1ll * e0 * a[i] % mod * qpow(s0, mod - 2) % mod);
		else printf("%lld\n", 1ll * e1 * a[i] % mod * qpow(s1, mod - 2) % mod);
	}
}