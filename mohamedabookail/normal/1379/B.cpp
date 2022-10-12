/**
*    author:  Mohamed Abo_Okail
*    created: 19/O7/2O2O
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
		ll l, r, m; cin >> l >> r >> m;
		if(m < l) {
			cout << l << ' ' << l << ' ' << l + (l - m) << endl;
		}
		else {
			ll a = 0, a1 = 0, a2 = 0, b = 0, c = 0, mod1 = 1e9, mod2 = 1e9;
			for (int i = l; i <= r; i++) {
				if(m % i < mod1) {
					a1 = i;
					mod1 = m % i;
				}
				if((m / i + 1) * i - m < mod2) {
					a2 = i;
					mod2 = (m / i + 1) * i - m;
				}
			}
			if(mod1 < mod2) {
				a = a1;
				b = r;
				c = r - mod1;
			}
			else {
				a = a2;
				b = l;
				c = l + mod2;
			}
			cout << a << ' ' << b << ' ' << c << endl;
		}
	}
}