/**
*    author:  Mohamed Abo_Okail
*    created: 12/O7/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return (x / _gcd(x, y) * y);
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	ll n, m; cin >> n >> m;
	ll x, y, k; cin >> x >> k >> y;
	vector < ll > a(n + 1), b(m), c(n + 1);
	map < ll, bool > mp;
	ll cnt = 0, ans = 0, mx = 0, indx = 0;
	bool bol = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	c = a;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		mp[b[i]] = 1;
	}
	for (int i = 0; i < n; i++) {
		if(n == m && a[i] != b[i]) bol = 0;
		if(mp[a[i]]) a[i] = -1;
	}
	a[n] = -1;
	c[n] = 0;
	for (int i = 0; i <= n; i++) {
		if(a[i] == -1) {
			ll mn1 = 1e18, mn2 = 1e18, mn3 = 1e18;
			if(cnt < k && c[i] <= mx && c[indx] <= mx) {
				bol = 0;
				break;
			}
			if(cnt >= k) {
				mn1 = cnt / k * x + cnt % k * y; 
			}
			if(c[i] > mx || c[indx] > mx) {
				mn2 = cnt * y;
			}
			if(cnt >= k) {
				mn3 = x + (cnt - k) * y;
			}
			ans += min(mn1, min(mn2, mn3));
			cnt = 0;
			mx = 0;
			indx = i;
		}
		else cnt++, mx = max(mx, a[i]);
	}
	cout << (bol ? ans : -1) << endl;
}