/**
*    author:  Mohamed Abo_Okail
*    created: 17/O7/2O2O
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
		ll b1 = 1, b2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		reverse(v.begin(), v.end());
		for (int i = 1; i < n; i++) {
			if(v[i] >= v[i - 1]) b1++;
			else break;
		}
		for (int i = b1; i < n; i++) {
			if(v[i] <= v[i - 1]) b2++;
			else break;
		}
		cout << n - (b1 + b2) << endl;
	}
}