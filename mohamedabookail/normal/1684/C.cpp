/**
*    author:  Mohamed Abo Okail
*    created: 19/O5/2O22
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
	
	ll t; cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector < vector < ll > > g(n, vector < ll > (m));
		vector < vector < ll > > g2(n, vector < ll > (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
				g2[i][j] = g[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			sort(all(g2[i]));
		}
		vector < ll > any;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(g[i][j] != g2[i][j]) {
					any.push_back(j);
				}
			}
		}
		if(sz(any) == 0) {
			cout << 1 << ' ' << 1 << endl;
			continue;
		}
		for (int i = 0; i < n; i++) {
			swap(g[i][any[0]], g[i][any[1]]);
		}
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) {
				ok &= (g[i][j] >= g[i][j - 1]);
			}
		}
		if(ok) {
			cout << ++any[0] << ' ' << ++any[1] << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}