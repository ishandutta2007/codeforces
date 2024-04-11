/**
*    author:  Mohamed Abo_Okail
*    created: 3O/O7/2O2O
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
		ll a = 6, b = 10, c = 14, d = n - 30;
		if(d > 0) {
			if(d == a || d == b || d == c) {
				c = 15;
				d = n - 31;
				if(d > 0) {
					cout << "YES" << endl;
					cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
				}
				else cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
				cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
			}
		}
		else cout << "NO" << endl;
	}
}