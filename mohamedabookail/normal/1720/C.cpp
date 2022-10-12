/**
*    author:  Mohamed Abo Okail
*    created: 18/O8/2O22
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
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
				cnt += (g[i][j] == '1');
			}
		}
		int mn = 5;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				int mx = (g[i][j] == '1') + (g[i][j + 1] == '1') + (g[i + 1][j] == '1') + (g[i + 1][j + 1] == '1');
				if(mx != 0) {
					mn = min(mn, mx);
				}
			}
		}
		if(mn == 4) {
			cout << cnt - 2 << endl;
		}
		else if(mn == 3) {
			cout << cnt - 1 << endl;
		}
		else {
			cout << cnt << endl;
		}
	}
}