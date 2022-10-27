#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
const int mod = 998244353;
const int N = 2e5;
int fact[N], ifact[N];
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b % 2 == 0)
	{
		int t = power(a , b / 2);
		return t * t % mod;
	}
	return a * power(a, b - 1) % mod;
}
int cnk(int n, int k)
{
	return fact[n] * ifact[n - k] % mod * ifact[k] % mod;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fact[0] = 1;
	for(int i = 1; i < N; i++)
	{
		fact[i] = fact[i - 1] * i % mod;
	}
	ifact[N - 1] = power(fact[N - 1], mod - 2);
	for(int i = N - 2; i >= 0; i--)
	{
		ifact[i] = ifact[i + 1] * (i + 1) % mod;
	}
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt0 = 0, cnt1 = 0;
		for(int i = 0; i < sz(s); i++)
		{
			if(s[i] == '0')
			{
				cnt0++;
			}
			else if(i + 1 < sz(s) && s[i + 1] == '1')
			{
				cnt1++;
				i++;
			}
		}
		cnt0++;
		if(cnt1 == 0)
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << cnk(cnt1 + cnt0 - 1, cnt1) << "\n";
		}
	}
	return 0;
}