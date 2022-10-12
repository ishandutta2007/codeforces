/**
 *    author:  Mohamed Abo_Okail
 *    created: 13/O2/2O2O
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
	ll a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		int oo; cin >> oo;
		if(oo == 1) a++;
		else b++;
	}
	if(a > 0 && b > 0) {
		cout << "2 1 ";
		a--; b--;
	}
	for (int i = 0; i < b; i++) {
		cout << "2 ";
	}
	for (int i = 0; i < a; i++) {
		cout << "1 ";
	}
	cout << o_o;
}