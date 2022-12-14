#include <bits/stdc++.h>
using namespace std;
int n, p, ans, pw[5555], b, jc[5555], injc[5555];
int dist(int i, int j)
{
	if (i <= j) return j - i;
	return n + j - i;
}
int binpow(int a, int t)
{
	int res = 1, pp = a;
	for (int i = t; i; i >>= 1)
	{
		if (i & 1) res = 1ll * res * pp % p;
		pp = 1ll * pp * pp % p;
	}
	return res;
}
int C(int n, int k)
{
	return 1ll * jc[n] * injc[k] % p * injc[n - k] % p;
}
int main()
{
	scanf("%d%d", &n, &p);
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		pw[i] = (pw[i - 1] + pw[i - 1]) % p;
	}
	jc[0] = 1;
	for (int i = 1; i <= n; i++) jc[i] = 1ll * jc[i - 1] * i % p;
	injc[n] = binpow(jc[n], p - 2);
	for (int i = n - 1; i >= 0; i--) injc[i] = 1ll * injc[i + 1] * (i + 1) % p;
	b = (n + 1) >> 1;
	for (int d = 0; d < b; d++)
	{
		if (d > 0)
		{
			for (int i = 0; i < d; i++)
			{
				ans = (1ll * n * C(d - 1, i) % p * jc[n - i - 3] % p * (n - d - 1 - (b - d - 1) * 2) + ans) % p;
			}
		}
		else 
		{
			ans = (1ll * n * jc[n - 2] % p * (n - d - 1 - (b - d - 1) * 2) + ans) % p;
		}
	}
	printf("%d\n", ans);
	return 0;
}