#include <cstdio>
#include <iostream>
#define MN 1000010
#define mod 998244353

int fac[MN], inv[MN];

int qpow(int x, long long p)
{
	int ans = 1;
	while(p)
	{
		if(p & 1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod; p >>= 1;
	}
	return ans;
}

int C(int a, int b) {return 1ll * fac[a] * inv[b] % mod * inv[a - b] % mod;}

int main()
{
	int n; scanf("%d", &n);
	fac[0] = inv[0] = inv[1] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	for(int i = 2; i <= n; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i <= n; i++) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
	
	int Ans = 0;
/*	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
		{
			if(i != n && j != n) continue;
			if(i == n && j == n) continue;
			int v = 1;
			if(i == n) v = n - j;
			if(j == n) v = n - i;
			Ans = (Ans + 1ll * qpow(mod - 1, n - i + n - j - 1) * C(n, i) % mod * C(n, j) % mod * qpow(3, 1ll * i * j + v)) % mod;
		}
	*/
//	int Ans = 0;
	for(int i = 0; i < n; i++) Ans = (Ans + 1ll * qpow(mod - 1, n - i - 1) * C(n, i) % mod * qpow(3, 1ll * i * n + n - i)) % mod;
	Ans = Ans * 2 % mod;
	for(int i = 0; i < n; i++)
	{
		int f = ((n - i - 1) & 1) ? -1 + mod : 1;
		f = f * 3ll % mod;
		Ans = (Ans + 1ll * f * C(n, i) % mod * (qpow((qpow(3, i) - 1 + mod) % mod, n) - qpow(3, 1ll * n * i) + mod)) % mod;
	}
	printf("%d\n", Ans);
}