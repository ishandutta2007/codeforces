/**
*    author:  Mohamed Abo_Okail
*    created: 2O/O7/2O2O
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
		vector < vector < ll > > grid((n), vector < ll > (m));
		bool bol = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(!i && !j || !i && j == m - 1) {
					if(grid[i][j] > 2) bol = 0;
					grid[i][j] = 2;
				}
				else if(i == n - 1 && j == m - 1 || i == n - 1 && !j) {
					if(grid[i][j] > 2) bol = 0;
					grid[i][j] = 2;
				}
				else if(!i || !j || i == n - 1 || j == m - 1) {
					if(grid[i][j] > 3) bol = 0;
					grid[i][j] = 3;
				}
				else {
					if(grid[i][j] > 4) bol = 0;
					grid[i][j] = 4;
				}
			}
		}
		if(bol) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << grid[i][j];
					if(j != m - 1) cout << ' ';
				}
				cout << endl;
			}
		}
		else cout << "NO" << endl;
	}
}