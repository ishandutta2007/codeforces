/**
 *    author:  Mohamed Abo_Okail
 *    created: 17/O3/2O2O
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
		ll a, b, c, d; cin >> a >> b >> c >> d;
		ll ans = b - a;
		cout << (!(ans % (c + d)) ? ans / (c + d) : -1) << o_o;
	}
}