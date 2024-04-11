/**
*    author:  Mohamed Abo Okail
*    created: 28/O3/2O21
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
		string s; cin >> s;
		bool ok = 1, ok2 = 0;
		for (int i = 1; i < sz(s); i++) {
			if(s[i] == s[i - 1] && s[i] == '1') {
				ok2 = 1;
			}
			if(s[i] == s[i - 1] && s[i] == '0' && ok2) {
				ok = 0;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}