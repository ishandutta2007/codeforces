/**
*    author:  Mohamed Abo Okail
*    created: O6/O6/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		bool ok = 1;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			ok &= x >= 0;
			mx = max(mx, x);
		}
		if(!ok) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl << mx + 1 << endl;
			for (int i = 0; i <= mx; i++) {
				cout << i << ' ';
			}
			cout << endl;
		}
	}
}