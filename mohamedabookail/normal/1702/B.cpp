/**
*    author:  Mohamed Abo Okail
*    created: 12/O9/2O22
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
		 int ans = 1;
		 for (int i = 0; i < sz(s); i++) {
			 mp[s[i]] == 1;
			 if(sz(mp) == 4) {
				ans++;
				mp.clear();
				mp[s[i]] = 1;
			 }
		 }
		 cout << ans << endl;
	}
}