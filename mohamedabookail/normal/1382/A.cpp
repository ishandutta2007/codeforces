/**
*    author:  Mohamed Abo_Okail
*    created: 21/O7/2O2O
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
		ll n, m; cin >> n >> m;
		vector < ll > a(n), b(m);
		map < ll, bool > mp;
		bool bol = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]] = 1;
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < m; i++) {
			if(mp[b[i]]) {
				cout << "YES" << endl;
				cout << 1 << ' ' << b[i] << endl;
				bol = 1;
				break;
			}
		}
		if(!bol) cout << "NO" << endl;
	}
}