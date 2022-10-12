/**
*    author:  Mohamed Abo Okail
*    created: 14/11/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t; cin >> t;
	while(t--) {
		ll a, b; cin >> a >> b;
		ll ans1 = a * (_lcm(a, b) / b);
		ll ans2 = b * (_lcm(a, b) / a);
		cout << -ans1 << ' ' << ans2 << endl;
	}
}