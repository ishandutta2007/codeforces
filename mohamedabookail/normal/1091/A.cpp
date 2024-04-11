/**
 *    author:  Mohamed Abo_Okail
 *    created: 14/O2/2O2O
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
	int a, b, c; cin >> a >> b >> c;
	if(b == min(b, c) && b != c) {
		c = b + 1;
	}
	else {
		b = c - 1;	
	}
	if(a >= b) {
		a = b - 1;
	}
	else {
		b = a + 1;
		c = b + 1;
	}
	cout << a + b + c << o_o;
}