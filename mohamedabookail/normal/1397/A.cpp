/**
*    author:  Mohamed Abo_Okail
*    created: 3O/O8/2O2O
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
		ll n; cin >> n;
		map < char, int > mp;
		vector < char > v;
		bool bol = 1;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < sz(s); j++) {
				mp[s[j]]++;
				if(mp[s[j]] == 1) v.push_back(s[j]);
			}
		}
		for (int i = 0; i < sz(v); i++) {
			if(mp[v[i]] % n) bol = 0;
		}
		cout << (bol ? "YES" : "NO") << endl;
	}
}