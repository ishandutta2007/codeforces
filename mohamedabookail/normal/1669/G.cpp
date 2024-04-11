/**
*    author:  Mohamed Abo Okail
*    created: 21/O4/2O22
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
		ll n, m;
		cin >> n >> m;
		vector < vector < char > > g(n, vector < char > (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
			}
		}
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if(g[j][k] == '*') {
						if(j + 1 < n && g[j + 1][k] == '.') {
							g[j][k] = '.';
							g[j + 1][k] = '*';
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << g[i][j];
			}
			cout << endl;
		}
	}
}