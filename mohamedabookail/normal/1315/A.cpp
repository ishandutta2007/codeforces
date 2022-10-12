/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O3/2O2O
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
	int t; cin >> t;
	while(t--) {
		ll a, b, x, y; cin >> a >> b >> x >> y;
		x++; y++;
		ll mn1 = x * b;
		ll mn2 = y * a;
		ll mn3 = (b - y + 1) * a;
		ll mn4 = (a - x + 1) * b;
		cout << a * b - min({mn1, mn2, mn3, mn4}) << o_o;
	}
}