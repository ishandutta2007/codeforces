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
		ll n; cin >> n;
		vector < ll > v(n);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < n - 1; i++) {
			if(v[i + 1] < v[i]) {
				ans += abs(v[i + 1] - v[i]);
			}
		}
		cout << ans << endl;
	}
}