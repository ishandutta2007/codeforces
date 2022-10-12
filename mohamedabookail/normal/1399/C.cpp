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
		map < ll , ll > mp;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			mp[oo]++;
		}
		for (int i = 2; i <= 100; i++) {
			ll flag = 0;
			for (int a = 1; a <= 50; a++) {
				for (int b = a; b <= 50; b++) {
					if(a == b && a + b == i) flag += mp[a] / 2;
					else if(a + b == i) flag += min(mp[a], mp[b]);
				}
			}
			ans = max(ans, flag);
		}
		cout << ans << endl;
	}
}