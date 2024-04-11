/**
*    author:  Mohamed Abo_Okail
*    created: 13/11/2O2O
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
	//freopen("x.in", "r", stdin);
	int t; cin >> t;
	while(t--) {
		ll n, m; cin >> n >> m;
		vector < vector < ll > > a(n, vector < ll > (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(a[i][j] % 2 == (i + j) % 2) {
					a[i][j]++;
				}
				if(j) cout << ' '; cout << a[i][j];
			}
			cout << endl;
		}
	}
}