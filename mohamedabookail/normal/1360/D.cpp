/**
 *    author:  Mohamed Abo_Okail
 *    created: 26/O5/2O2O
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
		if(k >= n) { cout << 1 << endl; continue; }
		vector < ll > v;
		for (ll i = 1; i * i <= n; i++) {
			if(!(n % i)) {
				v.push_back(i);
				if(i != n / i) v.push_back(n / i);
			}
		}
		sort(v.begin(), v.end());
		ll lo = 0, hi = v.size() - 1, mid = 0, ans = 0;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			if(v[mid] < k) {
				lo = mid + 1;
				ans = max(ans, v[mid]);
			}
			else if(v[mid] > k) {
				hi = mid - 1;
			}
			else {
				ans = v[mid];
				break;
			}
		}
		cout << n / ans << endl;
	}
}