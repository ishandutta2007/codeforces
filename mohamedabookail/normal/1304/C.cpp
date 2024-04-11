/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O3/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define o_o "\n"
#define ll long long
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n, m; cin >> n >> m;
		vector < pair < ll, pair < ll, ll > > > v(n);
		bool bol = 1;
		ll mx = m, mn = m;
		for (int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second.first >> v[i].second.second;
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			ll a, b, c, ans = 0;
			a = v[i].first;
			b = v[i].second.first;
			c = v[i].second.second;
			if(i) a -= v[i - 1].first;
			if(mn >= b && mx <= c) {
				ans = 0;
				mn = max(b, mn - a);
				mx = min(c, mx + a);
			}
			else if(mn >= b && mn <= c) {
				ans = 0;
				mn = max(b, mn - a);
				mx = c;
			}
			else if(mx >= b && mx <= c) {
				ans = 0;
				mn = b;
				mx = min(c, mx + a);
			}
			else {
				if(mn > c) {
					ans = mn - c;
					mx = c;
					mn = max(b, mn - a);
				}
				else if(mx < b) {
					ans = b - mx;
					mn = b;
					mx = min(c, mx + a);
				}
				else {
					ans = 0;
					mn = b;
					mx = c;
				}
			}
			if(ans > a) bol = 0;
		}
		cout << (bol ? "YES" : "NO") << o_o;
	}
}