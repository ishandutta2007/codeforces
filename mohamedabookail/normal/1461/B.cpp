/**
*    author:  Mohamed AboOkail
*    created: 12/12/2O2O
**/
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector < vector < char > > grid(n, vector < char > (m));
		vector < vector < int > > prf(n, vector < int > (m + 1));
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
				ans += (grid[i][j] == '*');
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				prf[i][j + 1] += prf[i][j] + (grid[i][j] == '*');
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if(grid[i][j] == '*') {
					int s = j - 1, e = j + 1, x = i + 1;
					while(s >= 0 && e < m && x < n) {
						if(prf[x][e + 1] - prf[x][s] == e - s + 1) ans++;
						else break;
						s--;
						e++;
						x++;
					}
				}
			}
		}
		cout << ans << endl;
	}
}