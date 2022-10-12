/**
*    author:  Mohamed Abo_Okail
*    created: 13/O7/2O2O
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
 
ll ok(ll mid) {
	return mid * 2 + mid * (mid - 1) / 2 * 3;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll ans = 0;
		while(n > 1) {
			ll lo = 1, hi = 1e9, mid = 0, flag = 0;
			while(lo <= hi) {
				mid = (lo + hi) / 2;
				if(ok(mid) > n) {
					hi = mid - 1;
				}
				else {
					flag = ok(mid);
					lo = mid + 1;
				}
			}
			n -= flag;
			ans ++;
		}
		cout << ans << endl;
	}
}