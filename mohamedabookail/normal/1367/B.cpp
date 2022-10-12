/**
 *    author:  Mohamed Abo_Okail
 *    created: 17/O6/2O2O
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
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			int oo; cin >> oo;
			if((i & 1) == (oo & 1)) continue;
			a += (oo & 1);
			b += !(oo & 1);
		}
		cout << (a == b ? a : -1) << endl;
	}
}