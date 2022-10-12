/**
*    author:  Mohamed Abo Okail
*    created: 1O/O6/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		ll n, l, r; cin >> n >> l >> r;
		vector < ll > a;
		map < ll , ll > mp;
		for (int i = 0; i < n; i++) {
			ll x; cin >> x;
			if(x < r) {
				if(mp[x] == 0)
					a.push_back(x);
				mp[x]++;
			}
		}
		n = sz(a);
		sort(all(a));
		ll ans = 0;
		map < ll , ll > fre;
		ll last = 0;
		for (int i = 0; i < n; i++) {
			fre[a[i]] = last + mp[a[i]];
			last = fre[a[i]];
		}
		for (int i = 0; i < n; i++) {
			if(a[i] * 2 >= l && a[i] * 2 <= r) {
				ans += mp[a[i]] * (mp[a[i]] - 1) / 2;
			}
			if(i == n - 1) continue;
			ll x = l - a[i], y = r - a[i];
			if(x < a[i]) {
				x = a[i] + 1;
			}
			if(x != a[i]) x--;
			ll lo = 0, hi = n - 1, mid = 0, cur1 = 0, cur2 = 0;
			while(lo <= hi) {
				mid = (lo + hi) / 2;
				if(a[mid] <= x) {
					cur1 = a[mid];
					lo = mid + 1;
				}
				else {
					hi = mid - 1;
				}
			}
			lo = 0, hi = n - 1, mid = 0;
			while(lo <= hi) {
				mid = (lo + hi) / 2;
				if(a[mid] <= y) {
					cur2 = a[mid];
					lo = mid + 1;
				}
				else {
					hi = mid - 1;
				}
			}
			if(cur1 >= cur2) continue;
			ans += mp[a[i]] * (fre[cur2] - fre[cur1]);
		}
		cout << ans << endl;
	}
}