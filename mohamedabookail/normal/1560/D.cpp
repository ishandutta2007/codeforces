/**
*    author:  Mohamed Abo Okail
*    created: 18/O8/2O21
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
	
	ll x = 1;
	vector < ll > a;
	while(x <= 1e18) {
		a.push_back(x);
		x *= 2;
	}
	vector < string > ar;
	for (int i = 0; i < sz(a); i++) {
		ar.push_back(to_string(a[i]));
	}
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int ans = 1e2;
		for (int i = 0; i < sz(ar); i++) {
			string x = ar[i];
			int indx = 0;
			for (int j = 0; j < sz(s); j++) {
				if(indx < sz(x) && s[j] == x[indx]) {
					indx++;
				}
			}
			ans = min(ans, sz(s) - indx + sz(x) - indx);
		}
		cout << ans << endl;
	}
}