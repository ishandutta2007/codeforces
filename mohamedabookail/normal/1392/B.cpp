/**
*    author:  Mohamed Abo_Okail
*    created: 17/O8/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
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
		ll n, k; cin >> n >> k;
		vector < ll > v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		ll mx = *max_element(all(v));
		for (int i = 0; i < n; i++) {
			v[i] = mx - v[i];
		}
		mx = *max_element(all(v));
		if(!(k & 1)) {
			for (int i = 0; i < n; i++) {
				v[i] = mx - v[i];
			}
		}
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		cout << endl;
	}
}