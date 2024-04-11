/**
 *    author:  Mohamed Abo_Okail
 *    created: 12/O2/2O2O
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
		ll n, a, b; cin >> n >> a>> b;
		if(n == a && n == b) cout << 1;
		else if(n == a + b) cout << max(a, b) + 1;
		else cout << n - min(a, b) + 1;
		cout << o_o;
	}
}