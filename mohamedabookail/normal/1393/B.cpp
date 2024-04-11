/**
*    author:  Mohamed Abo_Okail
*    created: O9/O8/2O2O
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
 ll fre1[100001], fre2[100001];
int main() {
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll oo; cin >> oo;
		fre1[oo]++;
		fre2[fre1[oo]]++;
	}
	ll q; cin >> q;
	while(q--) {
		char ch; ll oo; cin >> ch >> oo;
		if(ch == '+') {
			fre1[oo]++;
			fre2[fre1[oo]]++;
		}
		else {
			fre2[fre1[oo]]--;
			fre1[oo]--;
		}
		if(fre2[8]) cout << "YES" << endl;
		else if(fre2[4] >= 2) cout << "YES" << endl;
		else if(fre2[6] && fre2[2] >= 2) cout << "YES" << endl;
		else if(fre2[4] && fre2[2] >= 3) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}