/**
*    author:  Mohamed Abo Okail
*    created: O3/O5/2O22
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
		if(sz(s) == 1) {
			cout << "Bob" << ' ' << (s[0] - 'a') + 1 << endl;
		}
		else {
			ll tot = 0;
			for (int i = 0; i < sz(s); i++) {
				tot += (s[i] - 'a') + 1;
			}
			if(sz(s) & 1) {
				tot -= min((s[0] - 'a' + 1), (s.back() - 'a' + 1)) * 2;
			}
			cout << "Alice" << ' ' << tot << endl;
		}
	}
}