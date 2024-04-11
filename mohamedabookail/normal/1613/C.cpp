/**
*    author:  Mohamed Abo Okail
*    created: 06/12/2O21
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
		ll n, h; cin >> n >> h;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if(h <= n) {
			cout << 1 << endl;
			continue;
		}
		if(n == 1) {
			cout << h << endl;
			continue;
		}
		ll ans = 0, cur = 0;
		for (int i = 1; i < n; i++) {
			cur += a[i] - a[i - 1];
			ans = max(ans, a[i] - a[i - 1]);
		}
		ans = max(ans, h - cur);
		ll lo = 1, hi = ans, mid = 0;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			ll flag = mid;
			for (int i = 1; i < n; i++) {
				flag += min(mid, a[i] - a[i - 1]);
			}
			if(flag >= h) {
				ans = min(ans, mid);
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		cout << ans << endl;
	}
}