#include <cstdio>
#include <algorithm>
#define MN 301000
#define mod 998244353

int a[MN], s[MN];

bool cmp(int a, int b) 
{
	return a > b;
}

int qpow(int x, int p)
{
	int ans = 1;
	while(p)
	{
		if(p & 1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod;
		p >>= 1;
	}
	return ans;
}

int main()
{
	int n; scanf("%d", &n); int inv = qpow(n, mod - 2);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++) s[i] = (s[i - 1] + a[i]) % mod;
	for(int k = 1; k <= n; k++)
	{
		int ans = 0;
		for(int i = 0; i * k < n; i++)
			ans = (ans + 1ll * (s[std::min(n, (i + 1) * k)] - s[i * k] + mod) % mod * i % mod) % mod;
		ans = 1ll * ans * inv % mod;
		printf("%d ", ans);
	}
}