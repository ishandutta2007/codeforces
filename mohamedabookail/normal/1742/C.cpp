/**
*    author:  Mohamed Abo Okail
*    created: 13/1O/2O22
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
		vector < vector < char > > g(8, vector < char> (8));
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> g[i][j];
			}
		}
		char ans = '0';
		for (int i = 0; i < 8; i++) {
			int cnt = 0;
			for (int j = 0; j < 8; j++) {
				cnt += (g[i][j] == g[i][0]);
			}
			if(cnt == 8 && g[i][0] == 'R') {
				ans = g[i][0];
			}
		}
		for (int i = 0; i < 8; i++) {
			int cnt = 0;
			for (int j = 0; j < 8; j++) {
				cnt += (g[j][i] == g[0][i]);
			}
			if(cnt == 8 && g[0][i] == 'B') {
				ans = g[0][i];
			}
		}
		cout << ans << endl;
	}
}