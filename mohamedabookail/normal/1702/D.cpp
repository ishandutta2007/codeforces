/**
*    author:  Mohamed Abo Okail
*    created: 12/O9/2O22
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
		 string s; cin >> s;
		 int n;
		 cin >> n;
		 map < char , int > mp;
		 for (int i = 0; i < sz(s); i++) {
			 mp[s[i]]++;
		 }
		 char ch = '0';
		 for (int i = 0; i < 26; i++) {
			 if(mp[char('a' + i)]) {
				 if(mp[char('a' + i)] * (i + 1) > n) {
					ch = char('a' + i);
					break;
				 }
				 else {
					n -= mp[char('a' + i)] * (i + 1);
				 }
			 }
		 }
		 string ans = "";
		 for (int i = 0; i < sz(s); i++) {
			 if(s[i] < ch || ch == '0') {
				 ans.push_back(s[i]);
			 }
			 else if(s[i] == ch && n >= (ch - 'a' + 1)) {
				 ans.push_back(s[i]);
				 n -= (ch - 'a' + 1);
			 }
		 }
		 cout << ans << endl;
	}
}