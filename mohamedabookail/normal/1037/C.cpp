/**
*    author:  Mohamed Abo_Okail
*    created: 26/O6/2O2O
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
	int n; string a, b; cin >> n >> a >> b;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if(a[i] != b[i]) {
			if(i + 1 < n && a[i + 1] != b[i + 1] && a[i] != a[i + 1]) i ++;
			ans ++;
		}
	}
	cout << ans << endl;
}