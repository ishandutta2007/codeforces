/**
*    author:  Mohamed Abo_Okail
*    created: 28/O6/2O2O
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
	while(t --) {
		ll n, x, y; cin >> x >> y >> n;
		ll lo = 0, hi = 1e9, mid = 0, ans = 0;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			if(mid * x + y <= n) {
				ans = mid * x + y;
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		cout << ans << endl;
	}
}