/**
*    author:  Mohamed Abo_Okail
*    created: 24/O6/2O2O
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
	int n; cin >> n;
	vector < string > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int size = sz(v[0]);
	string t;
	for (int i = 0; i < size; i++) {
		map < char, bool > mp;
		char ch = 'a';
		for (int j = 0; j < n; j++) {
			string s = v[j];
			mp[s[i]] = 1;
			if(s[i] != '?') ch = s[i];
		}
		if(sz(mp) == 1 || (sz(mp) == 2 && mp['?'])) t.push_back(ch);
		else t.push_back('?');
	}
	cout << t << endl;
}