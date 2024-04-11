/**
*    author:  Mohamed Abo Okail
*    created: 1O/O4/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int t; cin >> t;
	while(t--) {
		ll a, b; cin >> a >> b;
		string s; cin >> s;
		ll aa = a, bb = b;
		for (int i = 0; i < sz(s); i++) {
			if(s[i] == '0' && a > 0) {
				a--;
			}
			else if(s[i] == '1' && b > 0) {
				b--;
			}
		}
		for (int i = 0; i < sz(s) / 2; i++) {
			if(s[i] == s[sz(s) - i - 1] && s[i] == '?') {
				continue;
			}
			else {
				if(s[i] == '?') {
					if(s[sz(s) - i - 1] == '0' && a >= 1) {
						s[i] = '0';
						a--;
					}
					if(s[sz(s) - i - 1] == '1' && b >= 1) {
						s[i] = '1';
						b--;
					}
				}
				else if(s[sz(s) - i - 1] == '?') {
					if(s[i] == '0' && a >= 1) {
						s[sz(s) - i - 1] = '0';
						a--;
					}
					if(s[i] == '1' && b >= 1) {
						s[sz(s) - i - 1] = '1';
						b--;
					}
				}
			}
		}
		for (int i = 0; i < sz(s) / 2; i++) {
			if(s[i] == s[sz(s) - i - 1] && s[i] == '?') {
				if(a >= 2) {
					s[i] = '0';
					s[sz(s) - i - 1] = '0';
					a -= 2;
				}
				else if(b >= 2) {
					s[i] = '1';
					s[sz(s) - i - 1] = '1';
					b -= 2;
				}
			}
		}
		if(sz(s) & 1) {
			if(s[sz(s) / 2] == '?') {
				if(a >= 1) {
					s[sz(s) / 2] = '0';
					a--;
				}
				else if(b >= 1) {
					s[sz(s) / 2] = '1';
					b--;
				}
			}
		}
		ll cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < sz(s); i++) {
			cnt0 += s[i] == '0';
			cnt1 += s[i] == '1';
		}
		string x = s;
		reverse(all(x));
		if(s == x && aa == cnt0 && bb == cnt1) {
			cout << s << endl;
		}
		else {
			cout << "-1" << endl;
		}
	}
}