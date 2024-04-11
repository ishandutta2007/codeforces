/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O4/2O2O
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
	ll k, n, s, p; cin >> k >> n >> s >> p;
	ll ans = 0, flag = 0;
	flag = (n + s - 1) / s;
	flag *= k;
	ans = (flag + p - 1) / p;
	cout << ans << o_o;
}