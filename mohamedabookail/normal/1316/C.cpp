/**
 *    author:  Mohamed Abo_Okail
 *    created: O4/O3/2O2O
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
	ll n, m, p; cin >> n >> m >> p;
	ll ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++) {
		ll oo; cin >> oo;
		if(oo % p) ans1 = i;
	}
	for (int i = 0; i < m; i++) {
		ll oo; cin >> oo;
		if(oo % p) ans2 = i;
	}
	cout << ans1 + ans2 << o_o;
}