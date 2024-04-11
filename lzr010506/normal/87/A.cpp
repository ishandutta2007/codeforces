#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll x, ll y)
{
	while(y)
	{
		ll z = y;
		y = x % y;
		x = z;
	}
	return x;
}

int main()
{
	ll a, b;
    cin >> a >> b;
    ll d = gcd(a, b);
    d = (a * b) / d;
    ll x = d / a, y = d / b;
    if (a < b) y ++;
    else x ++;
    if (x > y) cout << "Dasha\n";
    else if (x < y) cout << "Masha\n";
    else cout << "Equal\n";
    return 0;
}