#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll n , m , k;
ll t(ll x)
{
	ll res = 0;
	for(ll i = 1; i <= n; i++)
		if(x % i == 0 && x / i <= m)
			res++;
	return res;
}
ll c(ll x)
{
	ll res = 0;
	for(ll i = 1; i <= n; i++)
		res += min(x / i , m);
	return res;
}
ll bs(ll l , ll r)
{
	if(r - l <= 1)
	{
		if(k >= c(r) - t(r) + 1 && k <= c(r))
			return r;
		return l;
	}
	ll m = (l + r) / 2;
	if(c(m) >= k)
		return bs(l , m);
	return bs(m , r);
}
int main()
{
	cin >> n >> m >> k;
	cout << bs(1 , n * m) << endl;
}