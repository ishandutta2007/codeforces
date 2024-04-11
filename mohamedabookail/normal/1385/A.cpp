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
		ll x, y, z; cin >> x >> y >> z;
		if(x == y && y == z) {
			cout << "YES" << endl;
			cout << x << ' ' << y << ' ' << z << endl;
		}
		else if(x == z && y < x) {
			cout << "YES" << endl;
			cout << x << ' ' << y << ' ' << 1 << endl;
		}
		else if(y == z && x < y) {
			cout << "YES" << endl;
			cout << x << ' ' << y << ' ' << 1 << endl;
		}
		else if(x == y && z < x) {
			cout << "YES" << endl;
			cout << x << ' ' << z << ' '  << 1 << endl;
		}
		else cout << "NO" << endl;
	}
}