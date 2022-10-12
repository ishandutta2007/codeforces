/**
 *    author:  Mohamed Abo_Okail
 *    created: 12/O2/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}

ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		ll n, a, b; cin >> n >> a >> b;
		ll x = (n + 1) / 2, y = n / 2;
		if(a >= x || a >= b) cout << n;
		else {
			ll nemo = (x + a - 1) / a;
			ll ans = (nemo - 1) * b;
			cout << max((ans + x), n);
		}
		cout << o_o;
	}
}