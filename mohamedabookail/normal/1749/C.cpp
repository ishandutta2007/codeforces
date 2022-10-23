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
		sort(all(a));
		b = a;
		ll ans = 0, mx = a[n - 1] + n + 1;
		for (int i = mx; i > 0 ; i--) {
			bool ok = 1;
			for (int j = i; j > 0 ; j--) {
				bool ok2 = 0;
				ll mn = 1e3, mxx = 0;
				for (int k = n - 1; k >= 0 ; k--) {
					if(a[k] <= j && !ok2) {
						mxx = max(mxx, a[k]);
						ok2 = 1;
					}
				}
				if(!ok2) {
					ok = 0;
					break;
				}
				for (int k = 0; k < n; k++) {
					if(a[k] == mxx) {
						a[k] += 1e3 + 1;
						mxx = 0;
					}
					mn = min(mn, a[k]);
				}
				for (int k = 0; k < n; k++) {
					if(a[k] == mn) {
						a[k] += j;
						break;
					}
				}
			}
			if(ok) {
				ans = i;
				break;
			}
			a.clear();
			a = b;
		}
		cout << ans << endl;
	}
}