/**
*    author:  Mohamed Abo Okail
*    created: O4/1O/2O21
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
		int n, h; cin >> n >> h;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(all(a));
		ll lo = 1, hi = 1e9 + 5, mid = 0, ans = -1;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			if(mid * (a[n - 1] + a[n - 2]) >= h) {
				ans = mid * 2;
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		if(ans / 2 * (a[n - 1] + a[n - 2]) - a[n - 2] >= h) {
			ans--;
		}
		cout << ans << endl;
	}
}