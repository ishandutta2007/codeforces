/**
*    author:  Mohamed Abo_Okail
*    created: 12/O9/2O2O
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
		ll n; cin >> n;
		vector < ll > a, b;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			if(oo > 0) a.push_back(oo);
			if(oo < 0) b.push_back(abs(oo));
		}
		ll zero = n - (sz(a) + sz(b));
		if((!sz(a) && zero) || (sz(a) + sz(b) < 5)) {
			cout << 0 << endl;
		}
		else {
			sort(all(a));
			sort(all(b));
			reverse(all(a));
			reverse(all(b));
			vector < ll > ans;
			ll sum = 0;
			if(sz(a) >= 5) {
				sum = a[0] * a[1] * a[2] * a[3] * a[4];
				ans.push_back(sum);
			}
			if(sz(a) >= 3 && sz(b) >= 2) {
				sum = a[0] * a[1] * a[2] * b[0] * b[1];
				ans.push_back(sum);
			}
			if(sz(a) >= 1 && sz(b) >= 4) {
				sum = a[0] * b[0] * b[1] * b[2] * b[3];
				ans.push_back(sum);
			}
			if(!sz(ans)) {
				vector < ll > d;
				for (int i = 0; i < sz(a); i++) {
					d.push_back(abs(a[i]));
				}
				for (int i = 0; i < sz(b); i++) {
					d.push_back(abs(b[i]));
				}
				sort(all(d));
				ll ans = d[0] * d[1] * d[2] * d[3] * d[4] * -1;
				if(zero) ans = 0;
				cout << ans << endl;
				continue;
			}
			sort(all(ans));
			cout << ans[sz(ans) - 1] << endl;
		}
	}
}