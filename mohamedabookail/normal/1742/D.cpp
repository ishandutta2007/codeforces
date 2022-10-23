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
		int n;
		cin >> n;
		vector < ll > a(n);
		ll ans = -1;
		map < ll , ll > mp;
		ll mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] == 1) {
				ans = i + n + 1;
			}
			mp[a[i]] = i + 1;
			mx = max(mx, a[i]);
		}
		for (int i = 1; i <= mx; i++) {
			for (int j = i + 1; j <= mx; j++) {
				if(mp[i] && mp[j] && _gcd(i , j) == 1) {
					ans = max(ans, mp[i] + mp[j]);
				}
			}
		}
		cout << ans << endl;
	}
}