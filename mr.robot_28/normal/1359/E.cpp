#include <bits/stdc++.h>
using namespace std;
#define int long long
const int cnst = 998244353;
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
		return t * t  % cnst;
	}
	else
	{
		int t= power(a, b / 2);
		t = t * t % cnst;
		return a * t % cnst;
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
		fact[i] = fact[i - 1] * i % cnst;
	}
	fact1[n] = power(fact[n], cnst - 2);
	for(int i = n - 1; i >= 0; i--)
	{
		fact1[i] = fact1[i + 1] * (i + 1) % cnst;
	}
	int ans = 0;
	for(int i = 1; n / i >= k; i++)
	{
		int c = n / i;
		c--;
		if(k == 1)
		{
			ans++;
		}
		else
		{
			ans += (fact[c] * fact1[k - 1] % cnst) * fact1[c - k + 1] % cnst;
		}
		if(ans >= cnst)
		{
			ans -= cnst;
		}
	}
	cout << ans;
    return 0;
}