/**
 *    author:  Mohamed Abo_Okail
 *    created: 15/O2/2O2O
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
	int a1, a2, a3, b1, b2, b3, n;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
	int x = a1 + a2 + a3, y = b1 + b2 + b3;
	x = (x + 4) / 5; y = (y + 9) / 10;
	cout << (x + y <= n ? "YES" : "NO") << o_o;
}