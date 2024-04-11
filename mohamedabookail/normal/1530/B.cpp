/**
*    author:  Mohamed Abo Okail
*    created: 06/O8/2O21
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
		vector < vector < char > > grid(n, vector < char > (m, '0'));
		for (int i = 0; i < m; i += 2) {
			grid[0][i] = '1';
			grid[n - 1][i] = '1';
		}
		for (int i = 2; i < n; i += 2) {
			if(i >= n - 2) break;
			grid[i][0] = '1';
			grid[i][m - 1] = '1';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << grid[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

}