/**
*    author:  Mohamed Abo Okail
*    created: O7/O4/2O22
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
 
	int n, k;
	cin >> n >> k;
	string s; cin >> s;
	vector < pair < ll , ll > > a(n + 1);
	for (int i = 0; i < n; i++) {
		if(s[i] == 'a') {
			a[i + 1].first = 1;
		}
		else {
			a[i + 1].second = 1;
		}
		a[i + 1].first += a[i].first;
		a[i + 1].second += a[i].second;
	}
	ll ans = 0, l = 0, r = 0;
	while(r < sz(a)) {
		ll x = a[r].first - a[l].first;
		ll y = a[r].second - a[l].second;
		if(min(x, y) <= k) {
			ans = max(ans, x + y);
			r++;
		}
		else {
			l++;
		}
	}
	cout << ans << endl;
}