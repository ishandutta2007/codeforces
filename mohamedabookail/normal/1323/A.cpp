/**
 *    author:  Mohamed Abo_Okail
 *    created: O7/O3/2O2O
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
		int n; cin >> n;
		vector < int > v(n);
		int inx = -1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if(v[i] % 2 == 0) inx = i;
		}
		if(inx != -1) {
			cout << 1 << o_o << inx + 1 << o_o;
		}
		else {
			if(n == 1) cout << -1 << o_o;
			else {
				cout << 2 << o_o;
				cout << 1 << ' ' << 2;
				cout << o_o;
			}
		}
	}
}