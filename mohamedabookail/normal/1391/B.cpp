/**
*    author:  Mohamed Abo_Okail
*    created: O9/O8/2O2O
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
		ll ans = 0;
		vector < vector < char > > v((n), vector < char > (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
			}
		}
		for (int i = 0; i < m - 1; i++) {
			if(v[n - 1][i] == 'D') ans++;
		}
		for (int i = 0; i < n; i++) {
			if(v[i][m - 1] == 'R') ans++;
		}
		cout << ans << endl;
	}
}