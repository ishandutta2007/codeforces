/**
*    author:  Mohamed Abo Okail
*    created: O2/O5/2O22
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
	vector < ll > a(n), any;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		any.push_back((a[i] + 1) / 2);
	}
	sort(all(any));
	ll ans = any[0] + any[1];
	for (int i = 1; i < n; i++) {
		ll x = (a[i] + a[i - 1] + 2) / 3;
		if(x > min(a[i], a[i - 1])) {
			ans = min(ans, (max(a[i], a[i - 1]) + 1) / 2);
		}
		else {
			ans = min(ans, x);
		}
	}
	for (int i = 2; i < n; i++) {
		ll mx = max(a[i], a[i - 2]);
		ll mn = min(a[i], a[i - 2]);
		ans = min(ans, mn + (mx - mn + 1) / 2);
	}
	cout << ans << endl;
}