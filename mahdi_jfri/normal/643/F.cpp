#include<bits/stdc++.h>
using namespace std;
#define ll unsigned int
#define pb push_back
const int maxn = 1e3 + 20;
ll cp[maxn];
ll c(ll a , ll b)
{
	if(a < b)
		return 0;
	vector<ll> x;
	for(ll i = 1; i <= b; i++)
		x.pb(i);
	ll mul = 1;
	for(ll i = 0; i < b; i++)
	{
		ll j = a - i;
		for(auto &num : x)
		{
			ll g = __gcd(num , j);
			num /= g;
			j /= g;
		}
		mul *= j;
	}
	return mul;
}
int main()
{
	ll n , p , k;
	cin >> n >> p >> k;
	for(ll i = 0; i <= p; i++)
		cp[i] = c(n , i);
	ll ans = 0;
	for(ll i = 1; i <= k; i++)
	{
		ll res = 0 , num = 1;
		for(ll j = 0; j <= min(p , n - 1); j++)
		{
			res += cp[j] * num;
			num = num * i;
		}
		res = res * i;
		ans ^= res;
	}
	cout << ans << endl;
}