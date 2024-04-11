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
	int n, m, k; cin >> n >> m >> k;
	vector < vector < char > > grid(n, vector < char > (m));
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if(grid[i][j] == '*') cnt = 0;
			else cnt ++;
			if(cnt >= k) ans ++;
		}
	}
	if(k == 1) return cout << ans, 0;
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if(grid[j][i] == '*') cnt = 0;
			else cnt ++;
			if(cnt >= k) ans ++;
		}
	}
	cout << ans << endl;
}