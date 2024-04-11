/**
 *    author:  Mohamed Abo_Okail
 *    created: 24/O2/2O2O
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
		ll a, b, c; cin >> a >> b >> c;
		ll ans = 1e12, x = a, y = b, z = c;
		for (ll i = 1; i < 20000; i++) {
			for (ll j = i; j < 20000; j += i) {
				for (ll k = j; k < 20000; k += j) {
					if(!(j % i) && !(k % j)) {
						ll f = abs(a - i) + abs(b - j) + abs(c - k);
						if(f < ans) {
							ans = f;
							x = i;
							y = j;
							z = k;
						}
					}
				}
			}
		}
		cout << ans << o_o;
		cout << x << ' ' << y << ' ' << z << o_o;
	}
}