#include <iostream>
#include <cstdio>
#define MN 201000
#define mod 998244353

int fac[MN], inv[MN], a[MN];

int C(int a, int b) {return 1ll * fac[a] * inv[b] % mod * inv[a - b] % mod;} 

int qpow(int x, int p)
{
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
	int n, k; scanf("%d%d", &n, &k);
	if(k == 1) return 0 * puts("0");
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]); a[n + 1] = a[1];
	
	fac[0] = inv[1] = inv[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	for(int i = 2; i <= n; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i <= n; i++) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
	
	int cnt = 0, m = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == a[i + 1]) cnt++;
		else m++;
	}
	
	int ans = 0;
	for(int i = 0; i * 2 <= m; i++)
	{
		ans = (ans + 1ll * C(m, i) * C(m - i, i) % mod * qpow(k - 2, m - i - i) % mod) % mod;
	}
	ans = 1ll * (qpow(k, m) - ans + mod) * qpow(2, mod - 2) % mod;
	printf("%lld\n", 1ll * ans * qpow(k, cnt) % mod);
}