/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O2/2O2O
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
		ll n, k; cin >> n >> k;
		bool bol = 0;
		ll mx = -1;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			if(oo == k) bol = 1;
			mx = max(mx, oo);
		}
		cout << (bol ? 1 : max(2ll, (k + mx - 1) / mx)) << o_o; 
	}
}