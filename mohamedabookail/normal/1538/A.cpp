/**
*    author:  Mohamed Abo Okail
*    created: 1O/O6/2O21
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
		vector < ll > a(n);
		ll mx = 0, mn = 1e9;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mn = min(mn, a[i]);
			mx = max(mx, a[i]);
		}
		ll idx1 = 0, idx2 = 0;
		for (int i = 0; i < n; i++) {
			if(a[i] == mx) {
				idx1 = i + 1;
			}
			if(a[i] == mn) {
				idx2 = i + 1;
			}
		}
		if(idx1 < idx2) swap(idx1, idx2);
		cout << min(idx1, min(n - idx2 + 1, idx2 + (n - idx1 + 1))) << endl;
	}
}