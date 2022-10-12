/**
*    author:  Mohamed Abo Okail
*    created: 16/01/2O22
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
		int n, m, a, b; cin >> n >> m >> a >> b;
		vector < vector < char > > g(n, vector < char > (m));
		bool ok1 = 0, ok2 = 0;
		a--; b--;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
				ok1 |= (g[i][j] == 'B');
				ok2 |= (g[i][j] == 'B' && (i == a || j == b));
			}
		}
		int ans = -1;
		if(g[a][b] == 'B') {
			ans = 0;
		}
		else if(ok2) {
			ans = 1;
		}
		else if(ok1) {
			ans = 2;
		}
		cout << ans << endl;
	}
}