/**
 *    author:  Mohamed Abo_Okail
 *    created: 2O/O3/2O2O
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
	int n; cin >> n;
	vector < int > v(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	int m; cin >> m;
	vector < int > x(m);
	for (ll i = 0; i < m; i++) {
		cin >> x[i];
	}
	for (ll i = 0; i < m; i++) {
		cout << sum - v[n - x[i]] << o_o;
	}
}