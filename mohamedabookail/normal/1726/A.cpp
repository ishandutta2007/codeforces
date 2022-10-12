/**
*    author:  Mohamed Abo Okail
*    created: 18/O9/2O22
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
		int n;
		cin >> n;
		vector < int > ar(n);
		int mx = 0, mn = 1e3;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			mx = max(mx, ar[i]);
			mn = min(mn, ar[i]);
		}
		if(ar[0] == mn || ar[n - 1] == mx) {
			cout << mx - mn << endl;
		}
		else {
			int ans = ar[n - 1] - ar[0];
			for (int i = 0; i < n - 1; i++) {
				ans = max(ans, ar[i] - ar[i + 1]);
			}
			for (int i = 1; i < n; i++) {
				ans = max(ans, ar[i] - ar[0]);
			}
			for (int i = 0; i < n - 1; i++) {
				ans = max(ans, ar[n - 1] - ar[i]);
			}
			cout << ans << endl;
		}
	}
}