/**
*    author:  Mohamed Abo_Okail
*    created: 26/O6/2O2O
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
	return x / _gcd(x, y) * y;
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int n; string s; cin >> n >> s;
	int sum = 0, mx = 0;
	vector < int > v;
	for (int i = 0; i < n; i++) {
		sum += s[i] - '0';
		mx = max(mx, s[i] - '0');
	}
	for (int i = 1; i < sum; i++) {
		if(!(sum % i)) {
			if(i >= mx) v.push_back(i);
		}
	}
	for (int i = 0; i < sz(v); i++) {
		int sm = 0;
		for (int j = 0; j < n; j++) {
			sm += s[j] - '0';
			if(sm == v[i]) sm = 0;
			if(sm > v[i]) break;
		}
		if(!sm) return cout << "YES" << endl, 0;
	}
	cout << (!sum ? "YES" : "NO") << endl;
}