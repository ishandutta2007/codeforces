/**
*    author:  Mohamed Abo Okail
*    created: 1O/O4/2O22
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
		bool ok = (sz(s) % 2 == 0);
		for (int i = 0; i < sz(s) / 2; i++) {
			ok &= (s[i] == s[sz(s) / 2 + i]);
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}