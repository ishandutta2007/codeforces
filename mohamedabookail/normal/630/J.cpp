/**
 *    author:  Mohamed Abo_Okail
 *    created: 11/O2/2O2O
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
	cout << n / 2520 << o_o;
}