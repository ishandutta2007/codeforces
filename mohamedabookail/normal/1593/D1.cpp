/**
*    author:  Mohamed Abo Okail
*    created: 19/1O/2O21
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
		int n; cin >> n;
		vector < int > a;
		map < int , bool > mp;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if(!mp[x]) a.push_back(x);
			mp[x] = 1;
		}
		sort(all(a));
		if(sz(a) == 1) {
			cout << -1 << endl;
			continue;
		}
		ll ans = 1e18;
		for (int i = 1; i < sz(a); i++) {
			ans = min(ans, 1LL * a[i] - a[i - 1]);
		}
		vector < int > aa;
		for (ll i = 1; i * i <= ans; i++) {
			if(ans % i == 0) {
				aa.push_back(i);
				aa.push_back(ans / i);
			}
		}
		sort(all(aa));
		for (int i = sz(aa) - 1; i >= 0; i--) {
			bool ok = 1;
			for (int j = 1; j < sz(a); j++) {
				ok &= ((a[j] - a[0]) % aa[i] == 0); 
			}
			if(ok) {
				cout << aa[i] << endl;
				break;
			}
		}
	}
}