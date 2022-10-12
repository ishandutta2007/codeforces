/**
 *    author:  Mohamed Abo_Okail
 *    created: 22/O6/2O2O
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
		ll a, b, c; cin >> a >> b >> c;
		if(a < b) swap(a, b);
		a += c;
		cout << min({a, b, (a + b) / 3}) << endl;
	}
}