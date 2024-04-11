/**
*    author:  Mohamed Abo_Okail
*    created: 12/O8/2O2O
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
		ll a, b, c, d; cin >> a >> b >> c >> d;
		ll cnt = 0;
		if(a & 1) cnt++;
		if(b & 1) cnt++;
		if(c & 1) cnt++;
		if(d & 1) cnt++;
		if(!cnt || cnt == 1) {
			cout << "YES" << endl;
			continue;
		}
		cnt = 0;
		if(a && b && c) {
			a--;
			b--;
			c--;
			d++;
		}
		if(a & 1) cnt++;
		if(b & 1) cnt++;
		if(c & 1) cnt++;
		if(d & 1) cnt++;
		if(!cnt || cnt == 1) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
}