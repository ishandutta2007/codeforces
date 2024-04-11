/**
*    author:  Mohamed Abo Okail
*    created: 1O/O5/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector < vector < ll > > g(n, vector < ll > (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ll cur = g[i][j];
				int x = i - 1, y = j - 1;
				while(x >= 0 && y >= 0) {
					cur += g[x][y];
					x--;
					y--;
				}
				x = i + 1, y = j + 1;
				while(x < n && y < m) {
					cur += g[x][y];
					x++;
					y++;
				}
				x = i - 1, y = j + 1;
				while(x >= 0 && y < m) {
					cur += g[x][y];
					x--;
					y++;
				}
				x = i + 1, y = j - 1;
				while(x  < n && y >= 0) {
					cur += g[x][y];
					x++;
					y--;
				}
				ans = max(ans, cur);
			}
		}
		cout << ans << endl;
	}
}