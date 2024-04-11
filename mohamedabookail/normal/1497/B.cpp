/**
*    author:  Mohamed Abo Okail
*    created: 29/O3/2O21
**/
#include <bits/stdc++.h>

using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		ll n, m; cin >> n >> m;
		vector < ll > a;
		map < ll, ll > mp;
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			if(oo % m == 0) {
				if(!cnt) {
					cnt++;
				}
			}
			else {
				mp[oo % m]++;
				if(mp[oo % m] == 1) {
					a.push_back(oo % m);
				}
			}
		}
		for (int i = 0; i < sz(a); i++) {
			if(!mp[a[i]]) continue;
			if(mp[m - a[i]]) {
				ll mx = max(mp[a[i]], mp[m - a[i]]);
				ll mn = min(mp[a[i]], mp[m - a[i]]);
				cnt += max(mx - mn - 1, 0LL) + 1;
				mp[a[i]] = 0;
				mp[m - a[i]] = 0;
			}
			else {
				cnt += mp[a[i]];
				mp[a[i]] = 0;
			}
		}
		cout << cnt << endl;
	}
}