/**
*    author:  Mohamed Abo_Okail
*    created: 29/O7/2O2O
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
	while(t--) {
		string s; cin >> s;
		int ans = 0;
		for (char i = '0'; i <= '9'; i++) {
			for (char j = '0'; j <= '9'; j++) {
				string str = "";
				for (int k = 0; k < sz(s); k++) {
					if(!sz(str) && s[k] == i) str.push_back(s[k]);
					else {
						if(sz(str) && str.back() == i && s[k] == j) str.push_back(s[k]);
						else if(sz(str) && str.back() == j && s[k] == i) str.push_back(s[k]);
					}
				}
				if(sz(str) && str.front() == str.back() && i != j) str.pop_back();
				ans = max(ans, sz(str));
			}
		}
		cout << sz(s) - ans << endl;
	}
}