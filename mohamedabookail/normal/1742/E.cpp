/**
*    author:  Mohamed Abo Okail
*    created: 13/1O/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

ll _gcd(ll x, ll y) { return (y == 0) ? x : _gcd(y, x % y); }

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector < ll > sum(n);
		ll mx = 0, sm = 0;
		for (int i = 0; i < n; i++) {
			sm += a[i];
			sum[i] = sm;
			mx = max(mx, a[i]);
			a[i] = mx;
		}
		while(k--) {
			ll x;
			cin >> x;
			ll lo = 0, hi = n - 1, mid = 0, ans = 0;
			while(lo <= hi) {
				mid = (lo + hi) / 2;
				if(a[mid] <= x) {
					ans = sum[mid];
					lo = mid + 1;
				}
				else {
					hi = mid - 1;
				}
			}
			cout << ans << ' ';
		}
		cout << endl;
	}
}