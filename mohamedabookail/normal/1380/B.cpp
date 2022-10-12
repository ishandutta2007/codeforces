/**
*    author:  Mohamed Abo_Okail
*    created: 12/O7/2O2O
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
	int tt; cin >> tt;
	while(tt--) {
		string s, t; cin >> s;
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < sz(s); i++) {
			if(s[i] == 'R') a++;
			else if(s[i] == 'P') b++;
			else c++;
		}
		if(a >= b && a >= c) {
			t.assign(sz(s), 'P');
		}
		else if(b >= a && b >= c) {
			t.assign(sz(s), 'S');
		}
		else if(c >= a && c >= b) {
			t.assign(sz(s), 'R');
		}
		cout << t << endl;
	}
}