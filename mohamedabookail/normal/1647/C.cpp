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
		if(g[0][0] == '1') {
			cout << -1 << endl;
			continue;
		}
		vector < ll > a, b, c, d;
		for (int i = n - 1; i >= 0 ; i--) {
			for (int j = m - 1; j >= 0 ; j--) {
				if(g[i][j] == '1') {
					if(j) {
						a.push_back(i + 1);
						b.push_back(j);
						c.push_back(i + 1);
						d.push_back(j + 1);
					}
					else {
						a.push_back(i);
						b.push_back(1);
						c.push_back(i + 1);
						d.push_back(1);
					}
				}
			}
		}
		cout << sz(a) << endl;
		for (int i = 0; i < sz(a); i++) {
			cout << a[i] << ' ' << b[i] << ' ' << c[i] << ' ' << d[i] << endl;
		}
	}
}