 /**
*    author:  Mohamed Abo Okail
*    created: 26/11/2O21
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
		ll n, l, r, k; cin >> n >> l >> r >> k;
		vector < ll > a;
		ll x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if(x >= l && x <= r) {
				a.push_back(x);
			}
		}
		sort(all(a));
		ll ans = 0;
		for (int i = 0; i < sz(a); i++) {
			if(k - a[i] >= 0) {
				ans++;
				k -= a[i];
			}
			else break;
		}
		cout << ans << endl;
	}
}