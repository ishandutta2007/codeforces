/**
 *    author:  Mohamed Abo_Okail
 *    created: 15/O4/2O2O
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
		ll x, n, m; cin >> x >> n >> m;
		while(x > 0 && n && x / 2 + 10 < x) {
			n--;
			x /= 2;
			x += 10;
		}
		while(x > 0 && m) {
			x -= 10;
			m--;
		}
		cout << (x > 0 ? "NO" : "YES") << o_o;
	}
}