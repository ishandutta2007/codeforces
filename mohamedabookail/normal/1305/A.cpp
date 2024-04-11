/**
 *    author:  Mohamed Abo_Okail
 *    created: O3/O3/2O2O
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
	ll t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++) {
			cout << a[i];
			if(i != n - 1) cout << ' ';
		}
		cout << o_o;
		for (int i = 0; i < n; i++) {
			cout << b[i];
			if(i != n - 1) cout << ' ';
		}
		cout << o_o;
	}
}