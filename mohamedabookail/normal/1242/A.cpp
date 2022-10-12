/**
 *    author:  Mohamed.Abo_Okail
 *    created: 08/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

ll _gcd(ll x, ll y)
{
	return ((!y) ? x : _gcd(y, x % y));
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	ll n; cin >> n;
	set <ll> st;
	for (ll i = 2; (i * i) <= n; i++)
	{
		if(n % i == 0)
		{
			st.insert(i);
			st.insert(n / i);
		}
	}
	st.insert(n);
	ll g = 0;
	for(auto i : st)
	{
		g = _gcd(g, i);
	}
	cout << g << endl;
}