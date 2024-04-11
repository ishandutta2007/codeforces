/**
*    author:  Mohamed Abo_Okail
*    created: 24/O7/2O2O
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
		ll n; cin >> n;
		vector < ll > v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		string s = "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc";
		cout << s << endl;
		char ch = 'd';
		for (int i = 0; i < n; i++) {
			string t;
			for (int j = 0; j < v[i]; j++) {
				t.push_back(s[j]);
			}
			string f(51, ch);
			ch++;
			t += f;
			s = t;
			cout << s << endl;
			if(ch == 'z') ch = 'd';
		}
	}
}