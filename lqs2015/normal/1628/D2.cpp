#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, iv = (mod + 1) / 2;
const int maxn = 2000000;
int pw[2222222], ipw[2222222], jc[2222222], injc[2222222], test, n, m, k, ans;
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
int C(int n, int k)
{
	if (n < k || n < 0 || k < 0) return 0;
	return (1ll * jc[n] * injc[k] % mod) * injc[n - k] % mod;
}
int main()
{
	pw[0] = 1;
	for (int i = 1; i <= maxn; i++) pw[i] = (pw[i - 1] + pw[i - 1]) % mod;
	ipw[maxn] = binpow(pw[maxn], mod - 2);
	for (int i = maxn - 1; i >= 0; i--) ipw[i] = (ipw[i + 1] + ipw[i + 1]) % mod;
	jc[0] = 1;
	for (int i = 1; i <= maxn; i++) jc[i] = 1ll * jc[i - 1] * i % mod;
	injc[maxn] = binpow(jc[maxn], mod - 2);
	for (int i = maxn - 1; i >= 0; i--) injc[i] = 1ll * injc[i + 1] * (i + 1) % mod;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d%d", &n, &m, &k);
		m = n - m; ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans = (1ll * pw[i] * i % mod * (C(n - i, m) - C(n - i - 1, m)) + ans) % mod;
		}
		ans = 1ll * ans * k % mod * ipw[n] % mod;
		printf("%d\n", (ans + mod) % mod);
	}
	return 0;
}