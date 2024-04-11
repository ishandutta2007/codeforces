/**
 *    author:  Mohamed Abo_Okail
 *    created: O3/O3/2O2O
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
	ll n, m; cin >> n >> m;
	vector < ll > v(n);
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (ll i = 1; i < min(n, 10000ll); i++) {
		for (ll j = i - 1; j >= 0; j--) {
			ans *= abs(v[i] - v[j]);
			ans %= m;
		}
	}
	cout << ans;
}