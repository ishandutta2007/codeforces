/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O6/2O2O
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
	return x / _gcd(x, y) * y;
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t --) {
		ll a, b, n; cin >> a >> b >> n;
		int cnt1 = 0, cnt2 = 0, c = a, d = b;
		if(a > n || b > n) {
			cout << 0 << endl;
			continue;
		}
		while(true) {
			a += b;
			cnt1 ++;
			if(a > n) break;
			b += a;
			cnt1 ++;
			if(b > n) break;
		}
		while(true) {
			d += c;
			cnt2 ++;
			if(d > n) break;
			c += d;
			cnt2 ++;
			if(c > n) break;
		}
		cout << min(cnt1, cnt2) << endl;
	}
}