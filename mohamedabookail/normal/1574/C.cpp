
/**
*    author:  Mohamed Abo Okail
*    created: 23/O9/2O21
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
	
	ll n; cin >> n;
	vector < ll > a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(all(a));
	ll m; cin >> m;
	while(m--) {
		ll x, y; cin >> x >> y;
		ll lo = 0, hi = n - 1, mid = 0, indx = n - 1;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			if(a[mid] >= x) {
				indx = mid;
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		ll ans = 2e18;
		for (int i = indx; i < min(indx + 100, n); i++) {
			ans = min(ans, max(x - a[i], 0LL) + max(y - (sum - a[i]), 0LL));
		}
		for (int i = indx - 1; i >= max(indx - 100, 0LL) ; i--) {
			ans = min(ans, max(x - a[i], 0LL) + max(y - (sum - a[i]), 0LL));
		}
		cout << ans << endl;
	}
}