/**
*    author:  Mohamed Abo_Okail
*    created: 28/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return (x / _gcd(x, y) * y);
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t --) {
		ll n, k; cin >> n >> k;
		vector < ll > v;
		ll x = 1;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			if(oo % k) {
				v.push_back((oo < k ? k - oo : (oo / k + 1) * k - oo));
			}
		}
		sort(v.begin(), v.end());
		for (int i = 1; i < sz(v); i++) {
			if(v[i] == v[i - 1] % k) v[i] = v[i - 1] + k;
		}
		sort(v.begin(), v.end());
		cout << (sz(v) ? v[sz(v) - 1] + 1 : 0) << endl;
	}
}