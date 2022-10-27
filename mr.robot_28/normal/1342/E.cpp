#include<bits/stdc++.h>
using namespace std;

#define int long long
const int const1 = 998244353;
vector <int> fact, fact1;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t *t % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t = t * t % const1;
		return t * a % const1;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	fact.resize(n + 1);
	fact1.resize(n + 1);
	fact[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		fact[i] = fact[i - 1] * i % const1;
	}
	fact1[n] = power(fact[n], const1 - 2);
	for(int i = n - 1; i >= 0; i--)
	{
		fact1[i] = fact1[i + 1] * (i + 1) % const1;
	}
	if(k >= n)
	{
		cout << 0;
		return 0;
	}
	int ans = (fact[n] * fact1[n - k] % const1) * fact1[k] % const1;
	if(k == 0)
	{
		cout << fact[n];
		return 0;
	}
	int sum  = power(n - k, n);
	for(int i = n - k - 1; i >= 1; i--)
	{
		int a = power(i, n);
		a = a * fact[n - k] % const1;
		a = a * fact1[i] % const1;
		a = a * fact1[n - k - i] % const1;
		if(i % 2 == (n - k) % 2)
		{
			sum += a;
		}
		else
		{
			sum += const1 - a;
		}
		if(sum >= const1)
		{
			sum -= const1;
		}
	}
	ans = ans * 2 % const1;
	cout << ans * sum % const1;
	return 0;
}