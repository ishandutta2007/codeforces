/**
*    author:  Mohamed Abo Okail
*    created: 22/11/2O21
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
		ll n, a, b; cin >> n >> a >> b;
		vector < ll > aa, bb;
		map < ll , bool > mp;
		aa.push_back(a);
		bb.push_back(b);
		mp[a] = 1;
		mp[b] = 1;
		for (int i = a - 1; i > 0 ; i--) {
			if(mp[i]) continue;
			bb.push_back(i);
			mp[i] = 1;
		}
		for (int i = b + 1; i <= n; i++) {
			if(mp[i]) continue;
			aa.push_back(i);
			mp[i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if(mp[i]) continue;
			if(sz(aa) < n / 2 && i > a) {
				aa.push_back(i);
			}
			else if(sz(bb) < n / 2 && i < b) {
				bb.push_back(i);
			}
		}
		ll mn = 1e9, mx = 0;
		for (int i = 0; i < sz(aa); i++) {
			mn = min(mn, aa[i]);
		}
		for (int i = 0; i < sz(bb); i++) {
			mx = max(mx, bb[i]);
		}
		if(sz(aa) == n / 2 && sz(bb) == n / 2 && mn == a && mx == b) {
			for (int i = 0; i < n / 2; i++) {
				cout << aa[i] << ' ';
			}
			for (int i = 0; i < n / 2; i++) {
				cout << bb[i] << ' ';
			}
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}