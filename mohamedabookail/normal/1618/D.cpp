/**
*    author:  Mohamed Abo Okail
*    created: 25/O4/2O22
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
		int n, k;
		cin >> n >> k;
		vector < ll > a(n);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ans += a[i];
		}
		sort(all(a));
		int start = n - (k * 2);
		a.erase(a.begin(), a.begin() + start);
		for (int i = 0; i < sz(a) / 2; i++) {
			ans -= a[i];
			ans -= a[i + sz(a) / 2];
			ans += a[i] / a[i + sz(a) / 2];
		}
		cout << ans << endl;
	}
}