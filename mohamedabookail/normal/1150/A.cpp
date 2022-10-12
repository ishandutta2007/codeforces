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
	int n, m, r; cin >> n >> m >> r;
	int mn = 1001, mx = -1;
	for (int i = 0; i < n; i++) {
		int oo; cin >> oo;
		mn = min(mn, oo);
	}
	for (int i = 0; i < m; i++) {
		int oo; cin >> oo;
		mx = max(mx, oo);
	}
	cout << (mx > mn ? (r / mn * mx + r % mn) : r) << o_o;
	
}