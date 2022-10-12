/**
*    author:  Mohamed Abo Okail
*    created: 25/1O/2O21
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
		map < char , bool > mp;
		for (int i = 0; i < sz(s); i++) {
			mp[s[i]] = 1;
		}
		char chh;
		for (char ch = 'a'; ch <= 'z'; ch++) {
			if(mp[ch]) {
				chh = ch;
				break;
			}
		}
		cout << chh << ' ';
		bool ok = 0;
		for (int i = 0; i < sz(s); i++) {
			if(s[i] == chh && !ok) {
				ok = 1;
				continue;
			}
			cout << s[i];
		}
		cout << endl;
	}
}