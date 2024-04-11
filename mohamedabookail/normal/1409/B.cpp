/**
*    author:  Mohamed Abo_Okail
*    created: O4/O9/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
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
		ll a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		ll a2 = a, b2 = b, x2 = x, y2 = y, n2 = n;
		ll flag = min(a - x, n);
		a -= flag;
		n -= flag;
		flag = min(b - y, n);
		b -= flag;
		
		flag = min(b2 - y2, n2);
		b2 -= flag;
		n2 -= flag;
		flag = min(a2 - x2, n2);
		a2 -= flag;

		cout << min(a * b, a2 * b2) << endl;
	}
}