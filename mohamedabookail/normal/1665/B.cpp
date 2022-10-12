/**
*    author:  Mohamed Abo Okail
*    created: O8/O4/2O22
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
 
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector < ll > a(n);
		map < ll , ll > mp;
		ll mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
			mx = max(mx, mp[a[i]]);
		}
		if(mx == n) {
			cout << 0 << endl;
			continue;
		}
		ll ans = 0;
		while(mx < n) {
			ans++;
			ll x = mx;
			mx *= 2;
			if(mx > n) {
				ans += n - (mx - x);
			}
			else {
				ans += x;
			}
		}
		cout << ans << endl;
	}
}