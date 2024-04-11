/**
*    author:  Mohamed Abo Okail
*    created: 19/O4/2O22
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
	
	int n;
	cin >> n;
	vector < ll > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 1e18;
	for (int i = 0; i < n; i++) {
		ll tot = 0, mx1 = 0, mx2 = 0;
		for (int j = i + 1; j < n; j++) {
			if(a[j] > mx1) {
				tot++;
				mx1 = a[j];
			}
			else {
				ll x = (mx1 + a[j] - 1) / a[j];
				x += (x * a[j] == mx1);
				tot += x;
				mx1 = a[j] * x;
			}
		}
		for (int j = i - 1; j >= 0; j--) {
			if(a[j] > mx2) {
				tot++;
				mx2 = a[j];
			}
			else {
				ll x = (mx2 + a[j] - 1) / a[j];
				x += (x * a[j] == mx2);
				tot += x;
				mx2 = a[j] * x;
			}
		}
		ans = min(ans, tot);
	}
	cout << ans << endl;
}