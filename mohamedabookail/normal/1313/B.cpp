/**
 *    author:  Mohamed Abo_Okail
 *    created: 11/O3/2O2O
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
	int t; cin >> t;
	while(t--) {
		ll n, a, b; cin >> n >> a >> b;
		cout << max(1ll, min(n, a + b - n + 1)) << ' ' << min(n, a + b - 1) << o_o;
	}
}