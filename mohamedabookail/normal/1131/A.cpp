/**
 *    author:  Mohamed.Abo_Okail
 *    created: 02/01/2020
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll x = (a + 2) * 2 + b * 2;
	ll y = (c + 2) * 2 + d * 2;
	ll ans = x + y;
	ans -= min((a + 2) * 2, (c + 2) * 2);
	cout << ans << endl;
}