/**
*    author:  Mohamed Abo Okail
*    created: 21/O2/2O22
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
		map < char , int > mp;
		for (int i = 0; i < 6; i++) {
			mp[s[i]] = i;
		}
		bool ok = 1;
		ok &= (mp['r'] < mp['R']);
		ok &= (mp['b'] < mp['B']);
		ok &= (mp['g'] < mp['G']);

		cout << (ok ? "YES" : "NO") << endl;
	}
}