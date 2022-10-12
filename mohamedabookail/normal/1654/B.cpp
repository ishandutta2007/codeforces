/**
*    author:  Mohamed Abo Okail
*    created: 2O/O3/2O22
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
		map < char, ll > mp;
		for (int i = 0; i < sz(s); i++) {
			mp[s[i]]++;
		}
		string ans = "";
		for (int i = 0; i < sz(s); i++) {
			if(mp[s[i]] == 1) {
				for (int j = i; j < sz(s); j++) {
					ans.push_back(s[j]);
				}
				break;
			}
			else {
				mp[s[i]]--;
			}
		}
		cout << ans << endl;
	}
}