/**
 *    author:  Mohamed Abo_Okail
 *    created: 23/O3/2O2O
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
		map < ll, ll > mp1, mp2;
		for (int i = 0; i < n; i++) {
			ll k; cin >> k;
			vector < ll > v(k);
			for (int j = 0; j < k; j++) {
				cin >> v[j];
			}
			for (int j = 0; j < k; j++) {
				if(!mp2[v[j]]) {
					mp1[i + 1] = 1;
					mp2[v[j]] = 1;
					break;
				}
			}
		}
		ll a = 0, b = 0;
		for (int i = 1; i <= n; i++) {
			if(!mp1[i]) {
				a = i;
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if(!mp2[i]) {
				b = i;
				break;
			}
		}
		if(a && b) {
			cout << "IMPROVE" << o_o;
			cout << a << ' ' << b << o_o;
		}
		else  cout << "OPTIMAL" << o_o;
	}
}