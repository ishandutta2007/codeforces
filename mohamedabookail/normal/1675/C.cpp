/**
*    author:  Mohamed Abo Okail
*    created: O9/O5/2O22
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
		int indx = 0;
		for (int i = 0; i < sz(s); i++) {
			if(s[i] == '1') {
				indx = i;
			}
		}
		ll ans = 0;
		for (int i = indx; i < sz(s); i++) {
			ans++;
			if(s[i] == '0') break;
		}
		cout << ans << endl;
	}
}