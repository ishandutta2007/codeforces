/**
*    author:  Mohamed Abo_Okail
*    created: 25/1O/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n, m; cin >> n >> m;
		vector < vector < ll > > a(n, vector < ll > (m));
		vector < vector < ll > > b(m, vector < ll > (n));
		vector < vector < ll > > c(n, vector < ll > (m));
		map < ll , ll > mp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				mp[a[i][j]] = i;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> b[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				c[i][j] = b[j][i];
			}
		}
		for (int i = 0; i < n; i++) {
			ll ans = c[i][0];
			int idx = mp[ans];
			for (int k = 0; k < m; k++) {
				cout << a[idx][k] << ' ';
			}
			cout << endl;
		}
	}
}