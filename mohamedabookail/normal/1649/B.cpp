/**
*    author:  Mohamed Abo Okail
*    created: O6/O3/2O22
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
		vector < ll > a(n);
		ll sum = 0, mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			mx = max(mx, a[i]);
		}
		sum -= mx;
		if(sum + mx == 0) {
			cout << 0 << endl;
		}
		else if(sum >= mx) {
			cout << 1 << endl;
		}
		else {
			cout << mx - sum << endl;
		}
	}
}