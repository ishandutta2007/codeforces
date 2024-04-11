/**
*    author:  Mohamed Abo_Okail
*    created: O5/O8/2O2O
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
		vector < ll > v(n);
		bool bol = 1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int i = 1; i < n; i++) {
			if(abs(v[i] - v[i - 1]) > 1) bol = 0;
		}
		cout << (bol ? "YES" : "NO") << endl;
	}
}