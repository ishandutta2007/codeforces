/**
*    author:  Mohamed Abo Okail
*    created: 2O/1O/2O22
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
		vector < ll > a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		ll ans = 0;
		int l = 0, r = n - 1;
		while(l <= r) {
			if(l == r) {
				ans += a[l];
				break;
			}
			if(b[l] < b[r]) {
				ans += a[l];
				a[l + 1] += b[l];
				l++;
			}
			else {
				ans += a[r];
				a[r - 1] += b[r];
				r--;
			}
		}
		cout << ans << endl;
	}
}