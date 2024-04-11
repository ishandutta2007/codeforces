/**
 *    author:  Mohamed Abo_Okail
 *    created: 16/O5/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
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
		ll n, k; cin >> n >> k;
		ll ans = n, m = n;
		for (int i = 2; i <= k; i++) {
			ll mn = 1e18 + 5, mx = -1;
			while(m) {
				mn = min(mn, m % 10);
				mx = max(mx, m % 10);
				m /= 10;
			}
			if(!mn) break;
			ans += mn * mx;
			m = ans;
		}
		cout << ans << endl;
	}
}