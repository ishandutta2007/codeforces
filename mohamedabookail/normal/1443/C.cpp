/**
*    author:  Mohamed Abo_Okail
*    created: O2/11/2O2O
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
		vector < ll > a(n), b(n);
		vector < pair < ll, ll > > p(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			p[i].first = a[i];
			p[i].second = b[i];
		}
		sort(all(p));
		reverse(all(p));
		ll ans = 0, cur = 0, mx = 0;
		vector < ll > x;
		for (int i = n - 1; i >= 0; i--) {
			mx = max(mx, p[i].first);
			x.push_back(mx);
		}
		reverse(all(x));
		for (int i = 0; i < n; i++) {
			cur += p[i].second;
			ans = max(ans, min(cur, x[i]));
		}
		cout << ans << endl;
	}
}