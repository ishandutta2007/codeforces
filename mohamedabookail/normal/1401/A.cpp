/**
*    author:  Mohamed Abo_Okail
*    created: 21/O8/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return (x / _gcd(x, y) * y);
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n, k; cin >> n >> k;
		if(n == k) cout << 0 << endl;
		else if(!n) cout << k << endl;
		else if(!k) cout << (n & 1 ? 1 : 0) << endl;
		else {
			if(k > n) cout << k - n << endl;
			else {
				if(((n & 1) && (k & 1)) || (!(n & 1) && !(k & 1))) cout << 0 << endl;
				else cout << 1 << endl;
			}
		}
	}
}