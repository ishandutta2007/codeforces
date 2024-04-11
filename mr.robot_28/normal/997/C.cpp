#include <bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 998244353;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t = t * t % const1;
		return a * t % const1;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> fact(n + 1), fact1(n + 1);
	fact[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		fact[i] = fact[i - 1] * i % const1;
	}
	fact1[n] = power(fact[n], const1 - 2);
	for(int i = n - 1; i >= 0; i--)
	{
		fact1[i] = (i + 1) * fact1[i + 1] % const1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int cur = (2 * fact[n] * fact1[i] % const1) * fact1[n - i] % const1;
		cur = cur * power(3, i) % const1;
		cur = cur * power(3, n * (n - i)) % const1;
		if(i % 2 == 0)
		{
			ans = (ans + cur) % const1;
		}
		else
		{
			ans = (ans + const1 - cur) % const1;
		}
	}
	for(int k = 0; k < n; k++)
	{
		int cur = power((1 - power(3, k) + const1) % const1, n) - power(const1 - power(3, k), n);
		if(cur < 0)
		{
			cur += const1;
		}
		cur %= const1;
		cur = 3 * cur * fact[n] % const1;
		cur = cur * fact1[k] % const1;
		cur = cur * fact1[n - k] % const1;
		if(k % 2 == 1)
		{
			cur = (const1 - cur) % const1;
		}
		ans = (ans + cur) % const1;
	}
	ans = const1 - ans;
	ans %= const1;
	cout << ans;
	return 0; 
}