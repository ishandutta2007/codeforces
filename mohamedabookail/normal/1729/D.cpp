/**
*    author:  Mohamed Abo Okail
*    created: 12/O9/2O22
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
		vector < ll > a(n), b(n), c(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			c[i] = b[i] - a[i];
		}
		sort(all(c));
		ll ans = 0, l = 0, r = n - 1;
		while(l < r) {
			if(l == r) break;
			if(c[l] + c[r] >= 0) {
				ans++;
				l++;
				r--;
			}
			else {
				l++;
			}
		}
		cout << ans << endl;
	}
}