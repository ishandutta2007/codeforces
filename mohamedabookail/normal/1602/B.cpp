/**
*    author:  Mohamed Abo Okail
*    created: 25/1O/2O21
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
		int n; cin >> n;
		map < ll , int > mp, mpp;
		vector < vector < ll > > g(n + 1, vector < ll > (n));
		for (int i = 0; i < n; i++) {
			cin >> g[0][i];
			mp[g[0][i]]++;
		}
		for (int i = 1; i <= n; i++) {
			mpp.clear();
			for (int j = 0; j < n; j++) {
				g[i][j] = mp[g[i - 1][j]];
				mpp[g[i][j]]++;
			}
			mp.clear();
			mp = mpp;
		}
		int q; cin >> q;
		while(q--) {
			ll x, k; cin >> x >> k;
			if(k >= n) k = n;
			cout << g[k][x - 1] << endl;
		}
	}
}