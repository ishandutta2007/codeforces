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
	
	string s; cin >> s;
	map < string , int > mp;
	for (int i = 0; i < sz(s); i++) {
		string a = "";
		for (int j = i; j < sz(s); j++) {
			a.push_back(s[j]);
			mp[a]++;
		}
	}
	int ans = 0;
	for(auto it : mp) {
		if(it.second > 1) {
			ans = max(ans, sz(it.first));
		}
	}
	cout << ans << endl;
}