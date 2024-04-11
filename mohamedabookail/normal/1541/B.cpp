/**
*    author:  Mohamed Abo Okail
*    created: 25/O6/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll ans = 0;
		map < pair < ll , ll > , bool > mp;
		for (int i = 0; i < n; i++) {
			ll cnt = 1;
			while(a[i] * cnt - (i + 2) < n && a[i] * cnt - (i + 2) > i) {
				if(a[a[i] * cnt - (i + 2)] == cnt) {
					mp[make_pair(i, a[i] * cnt - (i + 2))] = 1;
					ans++;
				}
				cnt++;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			ll cnt = 1;
			while(a[i] * cnt - (i + 2) < i && a[i] * cnt - (i + 2) < n) {
				if(a[i] * cnt - (i + 2) < 0) {
					cnt++;
					continue;
				}
				if(mp[make_pair(a[i] * cnt - (i + 2), i)] == 1) {
					cnt++;
					continue;
				}
				ans += a[a[i] * cnt - (i + 2)] == cnt;
				cnt++;
			}
		}
		cout << ans << endl;
	}
}