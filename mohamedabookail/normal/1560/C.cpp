/**
*    author:  Mohamed Abo Okail
*    created: 18/O8/2O21
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
	
	vector < ll > a;
	ll x = 1, sum = 0;
	for (int i = 0; i < 200000; i++) {
		a.push_back(x);
		sum += x;
		x += 2;
		if(sum >= 2e9) break;
	}
	for (int i = 1; i < sz(a); i++) {
		a[i] += a[i - 1];
	}
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll lo = 0, hi = sz(a) - 1, mid = 0, ans = 0;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			if(a[mid] <= n) {
				ans = mid;
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		if(a[ans] == n) {
			cout << ans + 1 << ' ' << 1 << endl;
			continue;
		}
		n -= a[ans];
		if(n <= (a[ans + 1] - a[ans]) / 2) {
			cout << n << ' ' << ans + 2 << endl;
		}
		else if(n == ((a[ans + 1] - a[ans]) + 1) / 2) {
			cout << ans + 2 << ' ' << ans + 2 << endl;
		}
		else {
			n -= ((a[ans + 1] - a[ans]) + 1) / 2;
			cout << ans + 2 << ' ' << (a[ans + 1] - a[ans]) / 2 - n + 1 << endl;
		}
	}
}