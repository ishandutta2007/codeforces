/**
*    author:  Mohamed Abo_Okail
*    created: 24/O6/2O2O
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
	// 1 10 11 - 100 101 110 111 - 1000 1001 1010 1011 1100 1101 1110 1111
	int n; cin >> n;
	vector < ll > a, b;
	a.push_back(1);
	ll ans = 0, mx = 1;
	while(mx <= n) {
		for (int i = 0; i < sz(a); i++) {
			if(a[i] <= n) ans ++;
			mx = max(mx, a[i]);
			b.push_back(a[i] * 10);
			b.push_back(a[i] * 10 + 1);
		}
		a.clear();
		a = b;
		b.clear();
	}
	cout << ans << endl;
}