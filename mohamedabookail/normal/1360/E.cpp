/**
 *    author:  Mohamed Abo_Okail
 *    created: 26/O5/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector < vector < char > > grid((n), vector < char > (n));
		bool bol = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if(grid[i][j] == '1' && grid[i + 1][j] == '0' && grid[i][j + 1] == '0') bol = 0;
			}
		}
		cout << (bol ? "YES" : "NO") << endl;
	}
}