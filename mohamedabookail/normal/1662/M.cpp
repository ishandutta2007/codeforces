/**
*    author:  Mohamed Abo Okail
*    created: 24/O4/2O22
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
		ll mx1 = 0, mx2 = 0;
		for (int i = 0; i < m; i++) {
			ll a, b;
			cin >> a >> b;
			mx1 = max(mx1, a);
			mx2 = max(mx2, b);
		}
		if(mx1 + mx2 > n) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			string s1(mx1, 'R');
			string s2(n - mx1, 'W');
			cout << s1 + s2 << endl;
		}
	}
}