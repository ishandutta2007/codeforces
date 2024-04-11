/**
 *    author:  Mohamed Abo_Okail
 *    created: 19/O3/2O2O
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
	ll n, k; cin >> n >> k;
	vector < ll > v;
	ll sum = 0, cnt = 1;
	for (int i = 0; i < n; i++) {
		ll oo; cin >> oo;
		if(oo + k > n) v.push_back(i), sum += oo;
	}
	for (int i = 1; i < v.size(); i++) {
		cnt = (cnt * (v[i] - v[i - 1]) % 998244353);
	}
	cout << sum << ' ' << cnt << o_o;
}