/**
*    author:  Mohamed Abo_Okail
*    created: 11/O7/2O2O
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
		ll ans = 0;
		for (ll i = 2; i * i <= n; i++) {
			if(!(n % i)) {
				ans = i;
				break;
			}
		}
		if(ans) cout << n / ans << ' ' << n - (n / ans);
		else cout << 1 << ' ' << n - 1;
		cout << endl;
	}
}