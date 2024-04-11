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
		ll a, b; cin >> a >> b;
		if(a == b) cout << 0;
		else if(a < b && !((b - a) % 2)) cout << 2;
		else if(a < b && (b - a) % 2) cout << 1;
		else if(a > b && !((a - b) % 2)) cout << 1;
		else cout << 2;
		cout << o_o;
	}
}