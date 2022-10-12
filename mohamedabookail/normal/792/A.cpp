/**
 *    author:  Mohamed Abo_Okail
 *    created: 23/O3/2O2O
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
	vector < ll > v(n);
	map < ll, ll > mp;
	ll mn = 1e18 + 1; 
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) {
		ll x = abs(v[i] - v[i - 1]);
		mn = min(mn, x);
		mp[x]++;
	}
	cout << mn << ' ' << mp[mn] << o_o;
}