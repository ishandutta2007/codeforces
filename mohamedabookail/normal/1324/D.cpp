/**
 *    author:  Mohamed Abo_Okail
 *    created: 12/O3/2O2O
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
	ll n; cin >> n;
	vector < ll > a(n), b(n), x, y, z;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		if(a[i] - b[i] > 0) x.push_back(a[i] - b[i]);
		else if(a[i] - b[i] < 0) y.push_back(a[i] - b[i]);
		else z.push_back(0);
	}
	for (int i = 0; i < y.size(); i++) {
		y[i] *= -1;
	}
	ll f = x.size();
	ans += f * (f - 1) / 2;
	ans += z.size() * f;
	sort(y.begin(), y.end());
	for (ll i = 0; i < x.size(); i++) {
		ll lo = 0, hi = y.size() - 1, mid = 0, ans2 = -1;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			if(mid < 0 || mid >= y.size()) break;
			if(y[mid] >= x[i]) {
				hi = mid - 1;
			}
			else {
				ans2 = max(ans2, mid);
				lo = mid + 1;
			}
		}
		ans += ans2 + 1;
	}
	cout << ans << o_o;
}