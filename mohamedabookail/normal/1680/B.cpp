/**
*    author:  Mohamed Abo Okail
*    created: 13/O5/2O22
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
		vector < vector < char > > g(n, vector < char > (m));
		int x = -1, y = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
				if(g[i][j] == 'R' && x == -1) {
					x = i;
					y = j;
				}
			}
		}
		if(g[0][0] == 'R') {
			cout << "YES" << endl;
			continue;
		}
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < y; j++) {
				ok &= (g[i][j] == 'E');
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}