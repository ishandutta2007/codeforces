/**
*    author:  Mohamed Abo Okail
*    created: O8/O3/2O22
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
		char ch; cin >> ch;
		bool ok = 0;
		for (int i = 0; i < sz(s); i++) {
			if(s[i] == ch) {
				if(i % 2 == 0) {
					ok = 1;
					break;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}