#include<bits/stdc++.h>
using namespace std;
#define int long long
const int CONST1 = 1e9 + 7;
int pow1(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b == 1)
	{
		return a % CONST1;
	}
	else if(b % 2 == 1)
	{
		int g = pow1(a, b / 2);
		g = (g * g) % CONST1;
		return (g * a) % CONST1;
	}
	else
	{
		int g = pow1(a, b / 2);
		return (g * g) % CONST1;
	}
}
int ok(int x)
{
	x = x % CONST1;
	while(x < 0)
	{
		x += CONST1;
	}
	return x;
}
const int maxn = 300;
int fact[maxn], ifact[maxn];
int inv(int x)
{
	return pow1(x, CONST1 - 2);
}
int C(int n, int k)
{
	return (fact[n] * ifact[k] % CONST1) * ifact[n - k] % CONST1;
}
signed main()
{
	int n, k;
	cin >> n >> k;
	fact[0] = 1;
	for(int i = 1; i < maxn; i++)
	{
		fact[i] = fact[i - 1] * i % CONST1;
	}
	ifact[maxn - 1] = inv(fact[maxn - 1]);
	for(int i = maxn - 2; i >= 0; i--)
	{
		ifact[i] = ifact[i + 1] * (i + 1) % CONST1;
	}
	int ans = 0;
	for(int i = 0; i <= n; i++)
	{
		int r = pow1(k - 1, i * n);
		int t = pow1((pow1(k, n - i)  % CONST1 - pow1(k - 1, n - i) + CONST1) % CONST1, n);
		(ans += ((t * r % CONST1) * pow1(-1, i) % CONST1 * C(n, i) % CONST1)) %= CONST1;
		ans = ok(ans);
	}
	cout << ans % CONST1;
	return 0;
}