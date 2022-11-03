#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll x;
ll bs(ll l , ll r)
{
	if(r - l == 1)
	{
		if(r * r * r == x)
			return r;
		return l;
	}
	ll m = (l + r) / 2;
	if(m * m * m > x)
		return bs(l , m);
	if(m * m * m == x)
		return m;
	return bs(m , r);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--)
	{
		ll a , b;
		cin >> a >> b;
		x = a * b;
		ll k = bs(1 , 1e6);
		if(k * k * k != x || a % k || b % k)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
}