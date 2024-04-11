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
	string t;
	for (int i = 0; i < sz(s); i++) {
		if(i + 1 < sz(s)) {
			if(s[i] != s[i + 1]) {
				t.push_back(s[i]);
				t.push_back(s[i + 1]);
				i ++;
			}
		}
	}
	cout << sz(s) - sz(t) << endl << t << endl;
}