/**
 *    author:  Mohamed Abo_Okail
 *    created: 13/O3/2O2O
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
		ll sm1 = 0, sm2 = 0;
		bool bol = 1;
		vector < ll > v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < n; i++) {
			sm1 += v[i];
			sm2 += v[n - i - 1];
			if(sm1 <= 0 || sm2 <=0) bol = 0;
		}
		cout << (bol ? "YES" : "NO") << o_o;
	}
}