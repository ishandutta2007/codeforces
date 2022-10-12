/**
*    author:  Mohamed Abo Okail
*    created: 25/O6/2O21
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
		ll n; cin >> n;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll ans = 0;
		sort(all(a));
		for (int i = 1; i < n; i++) {
			ans += a[i] - a[i - 1];
		}
		for (int i = 1; i < n; i++) {
			ans -= a[i] * i - a[i - 1];
			a[i] += a[i - 1];
		}
		cout << ans << endl;
	}
}