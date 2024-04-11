/**
 *    author:  Mohamed Abo_Okail
 *    created: 21/O4/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define line "\n"
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
	vector < ll > v;
	v.push_back(1);
	for (ll i = 1; i <= 64; i++) {
		v.push_back(pow(2, i));
	}
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll ans = 1;
		bool bol = 0;
		for (int i = 0; i < v.size(); i++) {
			ll sum = 0;
			for (int j = i; j < v.size(); j++) {
				sum += v[j];
				if(n % sum == 0 && j) {
					ans = n / sum;
					bol = 1;
					break;
				}
			}
			if(bol) break;
		}
		cout << ans << endl;
	}
}