/**
*    author:  Mohamed Abo Okail
*    created: 26/O6/2O22
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
		vector < vector < char > > g(8, vector < char > (8));
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> g[i][j];
			}
		}
		for (int i = 1; i < 7; i++) {
			for (int j = 1; j < 7; j++) {
				if(g[i][j] == '#' && g[i - 1][j - 1] == '#' && g[i - 1][j + 1] == '#') {
					cout << ++i << ' ' << ++j << endl;
					i = j = 8;
				}
			}
		}
	}
}