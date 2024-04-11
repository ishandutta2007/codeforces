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
	string s; cin >> s;
	char ch = 'a';
	bool bol = 0;
	for (int i = 0; i < sz(s); i++) {
		if(s[i] <= ch) {
			s[i] = ch;
			if(ch == 'z') { bol = 1; break; }
			ch ++;
		}
	}
	cout << (bol ? s : "-1") << endl;
}