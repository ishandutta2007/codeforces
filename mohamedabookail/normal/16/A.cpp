/**
*    author:  Mohamed Abo Okail
*    created: 22/O4/2O22
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
	
	int n, m;
	cin >> n >> m;
	vector < vector < char > > g(n, vector < char > (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
		}
	}
	bool ok = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			ok &= (g[i][j] == g[i][j - 1]);
		}
		if(!i) continue;
		ok &= (g[i][0] != g[i - 1][0]);
	}
	cout << (ok ? "YES" : "NO") << endl;
}