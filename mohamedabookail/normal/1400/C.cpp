/**
*    author:  Mohamed Abo_Okail
*    created: 28/O8/2O2O
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
		string s; cin >> s;
		int n; cin >> n;
		string str(sz(s), '1');
		bool bol = 1;
		for (int i = 0; i < sz(s); i++) {
			if(s[i] == '0') {
				if(i - n >= 0) str[i - n] = '0';
				if(i + n < sz(s)) str[i + n] = '0';
			}
		}
		for (int i = 0; i < sz(s); i++) {
			if(s[i] == '1') {
				if((i - n < 0 || i - n >= 0 && str[i - n] == '0') && (i + n >= sz(s) || i + n < sz(s) && str[i + n] == '0')) bol = 0;
			}
		}
		cout << (bol ? str : "-1") << endl;
	}
}