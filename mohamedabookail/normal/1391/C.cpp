/**
*    author:  Mohamed Abo_Okail
*    created: 12/O8/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return (x / _gcd(x, y) * y);
}
int main() {
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	ll ans = 1, cur = 1, mod = 1e9 + 7;
	for (int i = 1; i <= n; i++) {
		ans *= i;
		ans %= mod;
		if(i < n) {
			cur *= 2;
			cur %= mod;
		}
	}
	cout << (ans - cur + mod) % mod << endl;
}