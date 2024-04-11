/**
*    author:  Mohamed Abo Okail
*    created: 11/O3/2O22
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
		int n, m; cin >> n >> m;
		vector < vector < char > > g(n, vector < char > (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
			}
		}
		bool ok = 1;
		for (int i = 0; i < n && ok; i++) {
			for (int j = 0; j < m && ok; j++) {
				if(g[i][j] == '1') {
					if(i - 1 >= 0 && j - 1 >= 0) {
						if(g[i - 1][j] == '1' && g[i][j - 1] == '1' && g[i - 1][j - 1] != '1') {
							ok = 0;
						}
					}
					if(i + 1 < n && j - 1 >= 0) {
						if(g[i][j - 1] == '1' && g[i + 1][j] == '1' && g[i + 1][j - 1] != '1') {
							ok = 0;
						}
					}
					if(i + 1 < n && j + 1 < m) {
						if(g[i][j + 1] == '1' && g[i + 1][j] == '1' && g[i + 1][j + 1] != '1') {
							ok = 0;
						}
					}
					if(i - 1 >= 0 && j + 1 < m) {
						if(g[i - 1][j] == '1' && g[i][j + 1] == '1' && g[i - 1][j + 1] != '1') {
							ok = 0;
						}
					}
				}
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}