/**
*    author:  Mohamed Abo_Okail
*    created: 25/O6/2O2O
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
	return x / _gcd(x, y) * y;
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	ll n, m; cin >> n >> m;
	vector < ll > v(n);
	ll g = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if(i) g = _gcd(g, v[i] - v[i - 1]);
	}
	for (int i = 0; i < m; i++) {
		ll oo; cin >> oo;
		if(!(g % oo)) {
			cout << "YES" << endl;
			cout << v[0] << ' ' << i + 1 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}