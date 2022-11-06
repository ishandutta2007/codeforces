#include <iostream>
#include <cstdio>
#define mod 1000000007
#define MN 1510
#define MK 101000

int n, m, a, b, p, k;
int fac[MK], inv[MK]; 
int f[MN][MN], g[MN][MN];
int w[MN], s[MN];
int sf[MN], sg[MN], ssf[MN], ssg[MN];

int inc(int a, int b) {return (a += b) >= mod ? a - mod : a;}
int dec(int a, int b) {return (a -= b) < 0 ? a + mod : a;} 

int C(int a, int b) {if(a < b) return 0; return 1ll * fac[a] * inv[b] % mod * inv[a - b] % mod;}

int qpow(int x, int p)
{
	if(p < 0) return 0;
	int ans = 1;
	while(p)
	{
		if(p & 1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod; p >>= 1;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &k);
	p = 1ll * a * qpow(b, mod - 2) % mod; 
	fac[0] = inv[0] = inv[1] = 1;
	for(int i = 1; i <= 100000; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	for(int i = 2; i <= 100000; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i <= 100000; i++) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
	for(int i = 0; i <= m; i++) w[i] = 1ll * qpow(p, i) * qpow(dec(1, p), k - i) % mod * C(k, i) % mod;
	for(int i = 0; i <= m; i++) s[i] = i == 0 ? w[i] : inc(s[i - 1], w[i]);
	f[0][1] = 1; g[0][m] = 1; 
	for(int i = 1; i <= n; i++)
	{
		for(int j = m; j >= 1; j--)
		{
			sf[j] = inc(sf[j + 1], f[i - 1][j]);
			ssf[j] = inc(ssf[j + 1], 1ll * f[i - 1][j] * s[m - j] % mod);
		}
		for(int j = 1; j <= m; j++)
		{
			sg[j] = inc(sg[j - 1], g[i - 1][j]);
			ssg[j] = inc(ssg[j - 1], 1ll * g[i - 1][j] * s[j - 1] % mod);
		}
		for(int j = 1; j <= m; j++)
		{
			f[i][j] = dec(1ll * sf[1] * s[m - j] % mod * w[j - 1] % mod, inc(1ll * dec(1ll * sf[j] * s[m - j] % mod, ssf[j]) * w[j - 1] % mod, 1ll * sg[j - 1] * s[m - j] % mod * w[j - 1] % mod));
			g[i][j] = dec(1ll * sf[1] * s[j - 1] % mod * w[m - j] % mod, inc(1ll * dec(1ll * sg[j] * s[j - 1] % mod, ssg[j]) * w[m - j] % mod, 1ll * sf[j + 1] * s[j - 1] % mod * w[m - j] % mod));
		}
	}
	int Ans = 0;
	for(int j = 1; j <= m; j++) Ans = inc(Ans, f[n][j]);
	printf("%d\n", Ans);
}