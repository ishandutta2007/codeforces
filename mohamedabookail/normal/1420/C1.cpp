/**
*    author:  Mohamed Abo_Okail
*    created: 23/O9/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n, q; cin >> n >> q;
		vector < ll > a(n), b, c;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		b.push_back(a[0]);
		for (int i = 1; i < n; i++) {
			b.push_back(a[i] - a[i - 1]);
		}
		bool bol = 1;
		for (int i = 0; i < sz(b) - 1; i++) {
			if(bol && b[i + 1] < 0 || !bol && b[i + 1] > 0) {
				c.push_back(a[i]);
				bol = !bol;
			} 
		}
		c.push_back(a.back());
		if(!(sz(c) & 1)) {
			c.pop_back();
		}
		ll ans = 0;
		for (int i = 0; i < sz(c); i++) {
			ans += ((i & 1) ? -c[i] : c[i]);
		}
		cout << ans << endl;
	}
}