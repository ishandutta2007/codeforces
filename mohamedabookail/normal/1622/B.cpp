/**
*    author:  Mohamed Abo Okail
*    created: 27/12/2O21
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
		vector < ll > a(n), ans(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		string s; cin >> s;
		vector < pair < ll , ll > > aa, bb;
		for (int i = 0; i < n; i++) {
			if(s[i] == '1') {
				aa.push_back(make_pair(a[i], i));
			}
			else {
				bb.push_back(make_pair(a[i], i));
			}
		}
		sort(all(aa));
		sort(all(bb));
		ll x = 1, y = sz(bb) + 1;
		for (int i = 0; i < sz(aa); i++) {
			ans[aa[i].second] = y++;
		}
		for (int i = 0; i < sz(bb); i++) {
			ans[bb[i].second] = x++;
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}