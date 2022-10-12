/**
*    author:  Mohamed Abo Okail
*    created: O5/O5/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		string s; cin >> s;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			mx = max(mx, s[i] - 'a');
		}
		if(k >= mx) {
			string ans(n, 'a');
			cout << ans << endl;
		}
		else {
			char ch = 'a';
			int indx = -1;
			for (int i = 0; i < n; i++) {
				if(s[i] - 'a' > k) {
					indx = i;
					break;
				}
				ch = max(ch, s[i]);
			}
			for (int i = 0; i < n; i++) {
				if(s[i] <= ch) {
					s[i] = 'a';
				}
			}
			k -= (ch - 'a');
			ch = char(s[indx] - k);
			char ch2 = s[indx];
			for (int i = 0; i < n; i++) {
				if(s[i] > ch && s[i] <= ch2) {
					s[i] = ch;
				}
			}
			cout << s << endl;
		}
	}
}