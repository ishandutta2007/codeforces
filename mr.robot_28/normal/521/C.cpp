#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 1e9 + 7;
vector <int> fact, fact1;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if( b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % mod;
	}
	else
	{
		int t= power(a, b - 1);
		return t * a % mod;
	}
}
int cnk(int a, int b)
{
	if(a - b < 0)
	{
		return 0;
	}
	return fact[a] * fact1[a - b] % mod * fact1[b] % mod;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if(k == 0)
	{
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			sum = (sum * 10 + s[i] - '0') % mod;
		}
		cout << sum;
		return 0;
	}
	fact.resize(n + 1);
	fact1.resize(n + 1);
	fact[0] = 1;
	vector <int> powers(n + 1);
	powers[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		powers[i] = powers[i - 1] * 10 % mod;
	}
	for(int i = 1; i <= n; i++)
	{
		fact[i] = fact[i -1 ] * i % mod;
	}
	fact1[n] = power(fact[n], mod - 2);
	for(int i = n - 1; i >= 0; i--){
		fact1[i] = fact1[i + 1] * (i + 1) % mod;
	}
	int sum = 0;
	int ans = 0;
	vector <int> pref(n + 1);
	vector <int> pref1(n + 1);
	pref[0] = 0;
	pref1[0] = 0;
	for(int i = 1; i < n; i++)
	{
		pref1[i] = (pref1[i - 1] * 10 + s[i] - '0') % mod;
		pref[i] = pref[i - 1] + s[i] - '0';
	}
	if(k >= 2)
	{
	for(int i = 1; i + 1 < n; i++)
	{
		sum += (s[i] - '0');
	}
	ans += (sum * cnk(n - 1 - 1 - 1, k - 2)) % mod;
	if(ans >= mod)
	{
		ans -= mod;
	}
	for(int len = 2; len <= n - 2; len++)
	{
		sum -= pref1[len - 1];
		if(sum < 0)
		{
			sum += mod;
		}
		sum += pref[n - len - 1] * powers[len - 1] % mod;
		if(sum >= mod)
		{
			sum -= mod;
		}
		ans += (sum * cnk(n - 1 - len - 1, k - 2)) % mod;
		if(ans >= mod)
		{
			ans -= mod;
		}
	}
	}
	sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum = (sum * 10 + s[i] - '0') % mod;
		ans += sum * cnk(n - 1 - i - 1, k - 1) % mod;
		if(ans >= mod)
		{
			ans -= mod;
		}
	}
	sum = 0;
	for(int j = n - 1; j >= 1; j--)
	{
		sum = (sum + powers[n - j - 1] * (s[j] - '0')) % mod;
		ans += sum * cnk(j - 1, k - 1) % mod;
		if(ans >= mod)
		{
			ans -= mod;
		}
	}
	cout << ans;
    return 0;
}