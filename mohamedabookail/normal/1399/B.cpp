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
		vector < ll > a(n), b(n);
		ll mn1 = 1e9 + 5, mn2 = 1e9 + 5, ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mn1 = min(a[i], mn1);
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			mn2 = min(b[i], mn2);
		}
		for (int i = 0; i < n; i++) {
			if(a[i] > mn1 && b[i] > mn2) {
				ll flag = min(a[i] - mn1, b[i] - mn2);
				ans += flag;
				a[i] -= flag;
				b[i] -= flag;
				ans += a[i] - mn1;
				ans += b[i] - mn2;
			}
			else if(a[i] > mn1) {
				ans += a[i] - mn1;
			}
			else if(b[i] > mn2) {
				ans += b[i] - mn2;
			}
		}
		cout << ans << endl;
	}
}