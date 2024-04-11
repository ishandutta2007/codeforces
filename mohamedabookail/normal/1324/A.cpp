/**
 *    author:  Mohamed Abo_Okail
 *    created: 12/O3/2O2O
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
	ll t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > v(n);
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if(v[i] % 2) cnt++;
		}
		cout << (cnt == n || cnt == 0 ? "YES" : "NO") << o_o;
	}
}