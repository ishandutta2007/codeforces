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
	ll n, k; cin >> n >> k;
	vector < ll > a, b, c;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll t, x, y; cin >> t >> x >> y;
		if(x && y) a.push_back(t);
		else if(x) b.push_back(t);
		else if(y) c.push_back(t);
	}
	//sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	if(sz(a) + min(sz(b), sz(c)) < k) return cout << -1 << endl, 0;
	for (int i = 0; i < min(sz(b), sz(c)); i++) {
		a.push_back(b[i] + c[i]);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < k; i++) {
		ans += a[i];
	}
	cout << ans << endl;
}