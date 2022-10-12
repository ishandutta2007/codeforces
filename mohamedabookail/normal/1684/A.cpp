/**
*    author:  Mohamed Abo Okail
*    created: 19/O5/2O22
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
	
	ll t; cin >> t;
	while(t--) {
		string s; cin >> s;
		if(sz(s) == 2) {
			cout << s[1] << endl;
		}
		else {
			char ans = '9';
			for (int i = 0; i < sz(s); i++) {
				ans = min(ans, s[i]);
			}
			cout << ans << endl;
		}
	}
}