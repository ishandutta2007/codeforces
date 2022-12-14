#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, maxn = 2e5;
int test, n, k, jc[maxn + 10], injc[maxn + 10], inv[maxn + 10], way[111111], cur, ans;
int binpow(int a, int t)
{
	int res = 1, p = a;
	for (int i = t; i; i >>= 1)
	{
		if (i & 1) res = 1ll * res * p % mod;
		p = 1ll * p * p % mod;
	}
	return res;
}
void Init()
{
	jc[0] = 1;
	for (int i = 1; i <= maxn; i++) jc[i] = 1ll * jc[i - 1] * i % mod;
	injc[maxn] = binpow(jc[maxn], mod - 2);
	for (int i = maxn - 1; i >= 0; i--) injc[i] = 1ll * injc[i + 1] * (i + 1) % mod; 
	for (int i = 1; i <= maxn; i++) inv[i] = 1ll * injc[i] * jc[i - 1] % mod;
}
int C(int n, int k)
{
	if (n < 0 || k < 0 || n < k) return 0;
	return 1ll * jc[n] * injc[n - k] % mod * injc[k] % mod;
}
int main()
{
	scanf("%d", &test);
	Init();
	while(test--)
	{
		scanf("%d%d", &n, &k);
		memset(way, 0, sizeof(way));
		for (int i = 1; i <= n; i++) 
		{
			if ((k - 1) * (i - 1) > n) break;
			way[i] = 1ll * C(n - (k - 1) * (i - 1), i) * jc[i] % mod;
		}
		cur = 1;
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cur = 1ll * cur * inv[n + 1 - i] % mod;
			ans = (1ll * way[i] * cur + ans) % mod;
		}
		ans ++;
		printf("%d\n", (ans + mod) % mod);
	}
	return 0;
}