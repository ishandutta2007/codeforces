/**
*    author:  Mohamed Abo Okail
*    created: 22/O4/2O22
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
		bool ok = 1;
		int cnt = 1;
		for (int i = 1; i < sz(s); i++) {
			if(s[i] != s[i - 1]) {
				ok &= (cnt > 1);
				cnt = 1;
			}
			else {
				cnt++;
			}
		}
		ok &= (cnt > 1);
		cout << (ok ? "YES" : "NO") << endl;
	}
}