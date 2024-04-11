/**
*    author:  Mohamed Abo Okail
*    created: 2O/1O/2O22
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
		map < int , bool > row, col;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			row[x] = 1;
			col[y] = 1;
		}
		bool ok = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if(!row[i] && !col[j]) {
					ok = 1;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}