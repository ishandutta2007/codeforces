/**
*    author:  Mohamed Abo Okail
*    created: 19/O9/2O22
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
		ll n, x, y;
		cin >> n >> x >> y;
		string a, b;
		cin >> a >> b;
		vector < int > ar;
		for (int i = 0; i < n; i++) {
			if(a[i] != b[i]) {
				ar.push_back(i);
			}
		}
		if(sz(ar) & 1) {
			cout << -1 << endl;
		}
		else if(sz(ar) == 0) {
			cout << 0 << endl;
		}
		else if(sz(ar) == 2 && ar[0] + 1 == ar[1]) {
			cout << min(x, y * 2) << endl;
		}
		else {
			cout << 1LL * sz(ar) / 2 * y << endl;
		}
	}
}