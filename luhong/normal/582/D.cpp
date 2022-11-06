#include <iostream>
#include <cstdio>
#include <cstring>
#define MN 3500
#define mod 1000000007

int f[MN][2][MN], g[MN][2][MN];
int d[MN], n = 0, b[MN], c[MN];
char s[MN];
int p, a, Ans = 0; 

int S(int l, int r) {return 1ll * (l + r) * (r - l + 1) / 2 % mod;}
int inc(int a, int b) {return (a += b) >= mod ? a - mod : a;}

int calc(int C)
{
	if(C < p) return C + 1;
	else return 2 * p - C - 1;
}

int main()
{
	scanf("%d%d%s", &p, &a, s);
	if(a > 3330) return 0 * puts("0");
	f[0][0][0] = 1;
	for(int i = 1; i <= 3330; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			f[i][0][j] = inc(f[i][0][j], (1ll * f[i - 1][0][j] * S(1, p) + 1ll * f[i - 1][1][j] * S(1, p - 1)) % mod);
			if(j) f[i][1][j] = inc(f[i][1][j], (1ll * f[i - 1][0][j - 1] * S(1, p - 1) + 1ll * f[i - 1][1][j - 1] * S(1, p)) % mod);
		}
	}
	for(int i = 1; i <= 3330; i++)
		for(int j = i; j >= 0; j--) 
		{
			f[i][0][j] = inc(f[i][0][j], f[i][0][j + 1]);
			f[i][1][j] = inc(f[i][1][j], f[i][1][j + 1]);
		}
	int len = strlen(s);
	for(int i = 0; i < len; i++) b[len - i] = s[i] - '0';
	while(len)
	{
		int res = 0;
		for(int i = len; i >= 1; i--)
		{
			c[i] = (res * 10ll + b[i]) / p;
			res = (res * 10ll + b[i]) % p;
		}
		d[++n] = res;
		while(len && !c[len]) len--;
		memcpy(b, c, sizeof(c));
	}
	g[n + 1][0][0] = 1;
	for(int i = n; i >= 1; i--)
	{
		if(d[i])
		for(int j = 0; j <= n - i; j++)
		{
			for(int A = 0; A <= 1; A++)
			{
				for(int B = 0; B <= 1; B++)
				{
					int Min = A * p + 0 - B, Max = A * p + d[i] - 1 - B;
					if(!A) Ans = inc(Ans, 1ll * g[i + 1][A][j] * f[i - 1][B][std::max(a - j, 0)] % mod * S(calc(Min), calc(Max)) % mod);
					else Ans = inc(Ans, 1ll * g[i + 1][A][j] * f[i - 1][B][std::max(a - j, 0)] % mod * S(calc(Max), calc(Min)) % mod);
				}
			}
		}
		for(int j = 0; j <= n - i + 1; j++)
		{
			for(int A = 0; A <= 1; A++)
			{
				for(int B = 0; B <= 1; B++)
				{
					int C = A * p + d[i] - B;
					g[i][B][j] = inc(g[i][B][j], 1ll * (j - B >= 0 ? g[i + 1][A][j - B] : 0) * calc(C) % mod);
				}
			}
		}
	}
	for(int j = a; j <= n; j++) Ans = inc(Ans, g[1][0][j]);
	printf("%d\n", Ans);
}