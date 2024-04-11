/**
*    author:  Mohamed Abo Okail
*    created: 1O/O5/2O22
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
		int n, q;
		cin >> n >> q;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(all(a));
		reverse(all(a));
		for (int i = 1; i < n; i++) {
			a[i] += a[i - 1];
		}
		while(q--) {
			ll x;
			cin >> x;
			ll lo = 0, hi = n - 1, mid = 0, ans = -1;
			while(lo <= hi) {
				mid = (lo + hi) / 2;
				if(a[mid] >= x) {
					ans = mid + 1;
					hi = mid - 1;
				}
				else {
					lo = mid + 1;
				}
			}
			cout << ans << endl;
		}
	}
}