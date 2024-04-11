/**
*    author:  Mohamed Abo_Okail
*    created: 21/O8/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
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
		ll a1, a2, a3; cin >> a1 >> a2 >> a3;
		ll b1, b2, b3; cin >> b1 >> b2 >> b3;
		ll ans = 0;
		ll flag = min(a3, b2);
		a3 -= flag;
		b2 -= flag;
		ans += flag * 2;
		flag = min(a1, b3);
		a1 -= flag;
		b3 -= flag;
		flag = min(a3, b3);
		a3 -= flag;
		b3 -= flag;
		flag = min(a2, b2);
		a2 -= flag;
		b2 -= flag;
		flag = min(a2, b1);
		a2 -= flag;
		b1 -= flag;
		ans -= min(a2, b3) * 2;
		cout << ans << endl;
	}
}