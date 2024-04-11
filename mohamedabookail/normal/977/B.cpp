/**
*    author:  Mohamed Abo Okail
*    created: O1/11/2O21
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
	
	int n; cin >> n;
	string s; cin >> s;
	map < string , int > mp;
	int mx = 0;
	string ans = "";
	for (int i = 1; i < n; i++) {
		string x = "";
		x.push_back(s[i - 1]);
		x.push_back(s[i]);
		mp[x]++;
	}
	for(auto it : mp) {
		if(it.second >= mx) {
			mx = it.second;
			ans = it.first;
		}
	}
	cout << ans << endl;
}