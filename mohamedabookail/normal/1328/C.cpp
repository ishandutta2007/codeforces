/**
 *    author:  Mohamed Abo_Okail
 *    created: 26/O3/2O2O
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
		ll n; string s; cin >> n >> s;
		string a = "", b = "";
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if(s[i] == '1') {
				if(!ans) a += '0', b += '1';
				else a += '1', b += '0';
				ans = 1;
			}
			else if(s[i] == '2') {
				if(!ans) a += '1', b += '1';
				else a += '2', b += '0';
			}
			else {
				a += '0', b += '0';
			}
		}
		cout << b << o_o << a << o_o;
	}
}