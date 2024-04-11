/**
 *    author:  Mohamed Abo_Okail
 *    created: O1/O4/2O2O
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
	vector < pair < ll, ll > > v(n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	ans = max(v[0].first, v[0].second);
	for (int i = 1; i < n; i++) {
		ll a = v[i].first, b = v[i].second;
		if(max(a, b) <= ans) ans = max(a, b);
		else if(min(a, b) <= ans) ans = min(a, b);
		else return cout << "NO", 0;
	}
	cout << "YES" << o_o;
}