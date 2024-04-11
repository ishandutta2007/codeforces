#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, maxn = 1000000;
int test, n, num[1111111], jc[1111111], injc[1111111], inv[1111111], ans, d, sum[1111111], a[1111111], cnt, x, nm;
vector<int> v;
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
int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}
void Init()
{
	jc[0] = 1;
	for (int i = 1; i <= maxn; i++) jc[i] = 1ll * jc[i - 1] * i % mod;
	injc[maxn] = binpow(jc[maxn], mod - 2);
	for (int i = maxn - 1; i >= 0; i--) injc[i] = 1ll * injc[i + 1] * (i + 1) % mod;
	for (int i = 1; i <= maxn; i++) inv[i] = 1ll * injc[i] * jc[i - 1] % mod;
}
int calc(int d)
{
	cnt = v.size();
	for (int i = 0; i < cnt; i++) a[i] = v[i] / (n / d);
	int res = 1, fuc = 0;
	if (cnt == 1) return 1;
	res = jc[d - 2];
	for (int i = 0; i < cnt; i++) res = 1ll * res * injc[a[i]] % mod;
	for (int i = 0; i < cnt; i++) fuc = (fuc + a[i]) % mod;
	fuc = 1ll * fuc * fuc % mod;
	for (int i = 0; i < cnt; i++) fuc = (-1ll * a[i] * a[i] + fuc) % mod;
	fuc = 1ll * fuc * res % mod * n % mod;
	return fuc;
}
int calc2(int d)
{
	cnt = v.size();
	for (int i = 0; i < cnt; i++) a[i] = v[i] / (n / d);
	int res = 1, fuc = 0;
	if (cnt == 1) return 1;
	res = jc[d];
	for (int i = 0; i < cnt; i++) res = 1ll * res * injc[a[i]] % mod;
	return res;
}
int main()
{
	scanf("%d", &test);
	Init();
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) num[i] = sum[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x); 
			num[x] ++;
		}
		d = 0;
		for (int i = 1; i <= n; i++) d = gcd(d, num[i]);
		for (int i = 1; i <= n; i++) 
		{
			sum[gcd(i, n)] ++;
		}
		ans = 0;
		v.clear();
		for (int i = 1; i <= n; i++) 
		{
			if (num[i]) v.push_back(num[i]);
		}
		nm = 0;
		for (int i = 1; i <= n; i++)
		{
			if (n % i == 0 && d % (n / i) == 0)
			{
			//	cout << i << " " << calc(i) << " " << sum[i] <<  " " << calc2(i) << endl;
				ans = (1ll * calc(i) * sum[i] + ans) % mod;
				nm = (1ll * calc2(i) * sum[i] + nm) % mod;
			}
		}
	//	cout << nm << endl;
		ans = 1ll * ans * binpow(nm, mod - 2) % mod;
		printf("%d\n", (ans + mod) % mod);
	}
	return 0;
}