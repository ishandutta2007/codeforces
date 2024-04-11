/**
*    author:  Mohamed Abo_Okail
*    created: 2O/O7/2O2O
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
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			oo = abs(oo);
			if(i % 2) oo *= -1;
			cout << oo;
			if(i != n - 1) cout << ' ';
		}
		cout << endl;
	}
}