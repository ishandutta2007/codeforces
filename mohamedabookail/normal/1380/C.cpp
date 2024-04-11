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
	int t; cin >> t;
	while(t--) {
		ll n, x; cin >> n >> x;
		vector < ll > v(n);
		ll ans = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int i = n - 1; i >= 0 ; i--) {
			if(v[i] >= x) {
				ans++;
				continue;
			}
			cnt++;
			if(cnt * v[i] >= x) {
				ans++;
				cnt = 0;
			}
		}
		cout << ans << endl;
	}
}