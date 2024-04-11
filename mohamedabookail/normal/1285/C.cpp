/**
 *    author:  Mohamed Abo_Okail
 *    created: 13/O3/2O2O
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
	ll x; cin >> x;
	vector < ll > v;
	ll a = 1e12, b = 1e12;
	for (ll i = 1; i * i <= x; i++) {
		if(!(x % i)) {
			if(_gcd(i, x / i) == 1) {
				if(i + x / i < a + b) {
					a = i;
					b = x / i;
				}
			}
		}
	}
	cout << a << ' ' << b << o_o;
}