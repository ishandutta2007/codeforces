/**
*    author:  Mohamed Abo Okail
*    created: 31/O3/2O22
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

	int t;
	cin >> t;
	while(t--) {
		string s; cin >> s;
		map < char , int > mp;
		ll ans = 0;
		for (int i = 0; i < sz(s); i++) {
			mp[s[i]]++;
			if(mp[s[i]] == 2) {
				ans += 2;
				mp.clear();
			}
		}
		cout << sz(s) - ans << endl;
	}
}