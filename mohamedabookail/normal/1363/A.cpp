/**
 *    author:  Mohamed Abo_Okail
 *    created: 31/O5/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
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
		ll n, k; cin >> n >> k;
		ll a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			if(oo % 2) a++;
			else b++;
		}
		if(a >= k && b == 0 && k % 2 == 0) {
			cout << "NO" << endl;
			continue;
		}
		if(a >= k) {
			cout << "YES" << endl;
			continue;
		}
		if(k > b) {
			k -= b;
			if(k % 2 == 0) k++;
		}
		else k = 1;
		cout << (a >= k && k % 2 ? "YES" : "NO") << endl;
	}
}