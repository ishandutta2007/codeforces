/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O6/2O2O
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
	string s, t; cin >> s;
	bool bol = 0;
	for (int i = 0; i < sz(s); i++) {
		if(s[i] == '/') bol = 1;
		else {
			if(bol) t.push_back('/');
			t.push_back(s[i]);
			bol = 0;
		}
	}
	cout << (sz(t) ? t : "/") << endl;
}