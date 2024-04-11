/**
*    author:  Mohamed Abo_Okail
*    created: 19/O7/2O2O
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
		ll n; string s; cin >> n >> s;
		int cnt = 0;
		for (int i = 0; i < n - 6; i++) {
			string t;
			for (int j = i; j < i + 7; j++) {
				t.push_back(s[j]);
			}
			if(t == "abacaba") cnt++;
		}
		if(cnt > 1 || n < 7) {
			cout << "NO" << endl;
			continue;
		}
		if(cnt == 1) {
			for (int i = 0; i < n; i++) {
				if(s[i] == '?') s[i] = 'z';
			}
			cout << "YES" << endl << s << endl;
			continue;
		}
		string a = "abacaba", b = s;
		int indx = 0, cnt1 = 0;
		bool bol = 0;
		for (int i = 0; i < n - 6; i++) {
			string t;
			for (int j = i; j < i + 7; j++) {
				t.push_back(s[j]);
			}
			for (int j = 0; j < 7; j++) {
				if(t[j] == '?') t[j] = a[j];
			}
			if(t == a) {
				string fox1, fox2;
				for (int j = i + 7; j < i + 11; j++) {
					if(j < n) fox1.push_back(s[j]);
				}
				for (int j = i - 1; j >= max(i - 4, 0) ; j--) {
					fox2.push_back(s[j]);
				}
				if(fox1 == "caba" || fox2 == "caba") continue;
				bol = 1;
				for (int j = i; j < i + 7; j++) {
					if(s[j] == '?') s[j] = a[indx];
					indx++;
				}
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if(s[i] == '?') s[i] = 'z';
		}
		for (int i = 0; i < n - 6; i++) {
			string t;
			for (int j = i; j < i + 7; j++) {
				t.push_back(s[j]);
			}
			if(t == "abacaba") cnt1++;
		}
		if(bol && cnt1 == 1) cout << "YES" <<  endl << s << endl;
		else cout << "NO" << endl;
	}	
}