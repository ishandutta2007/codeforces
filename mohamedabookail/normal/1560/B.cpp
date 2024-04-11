/**
*    author:  Mohamed Abo Okail
*    created: 18/O8/2O21
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
		ll a, b, c, d1, d2; cin >> a >> b >> c;
		if(a > b) swap(a, b);
		if((b - a) * 2 < b || (b - a) * 2 < c) {
			cout << -1 << endl;
		}
		else if(c > b) {
			if(c - (b - a) > a && c - (b - a) < b) {
				cout << c - (b - a) << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if(c < a) {
			if(c + (b - a) > a && c + (b - a) < b) {
				cout << c + (b - a) << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if(c > a && c < b) {
			ll res1 = c - (b - a);
			ll res2 = c + (b - a);
			if(res1 >= 1) {
				ll mn = min(c, res1);
				ll mx = max(c, res1);
				if(mn >= 1 && mx >= (b - a) + 1 && mn - 1 == mx - ((b - a) + 1)) {
					cout << res1 << endl;
					continue;
				}
			}
			ll mn = min(c, res2);
			ll mx = max(c, res2);
			if(mn >= 1 && mx >= (b - a) + 1 && mn - 1 == mx - ((b - a) + 1)) {
				cout << res2 << endl;
				continue;
			}
			cout << -1 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}