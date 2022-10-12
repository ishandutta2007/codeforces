/**
*    author:  Mohamed Abo Okail
*    created: 21/O4/2O22
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
		ll n;
		cin >> n;
		map < char, ll > mp1, mp2;
		map < string , ll > mp3;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			mp1[s[0]]++;
			mp2[s[1]]++;
			mp3[s]++;
		}
		ll ans = 0;
		for(auto it : mp1) {
			ans += 1LL * it.second * (it.second - 1) / 2;
		}
		for(auto it : mp2) {
			ans += 1LL * it.second * (it.second - 1) / 2;
		}
		for(auto it : mp3) {
			ans -= 1LL * it.second * (it.second - 1);
		}
		cout << ans << endl;
	}
}