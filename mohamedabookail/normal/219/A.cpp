/**
*    author:  Mohamed Abo Okail
*    created: 08/12/2O21
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
	
	int n;
	string s;
	cin >> n >> s;
	map < char , int > mp;
	for (int i = 0; i < sz(s); i++) {
		mp[s[i]]++;
	}
	string x = "";
	for(auto it : mp) {
		if(it.second % n) {
			return cout << -1, 0;
		}
		string ss(it.second / n, it.first);
		x += ss;
	}
	string ans = "";
	for (int i = 0; i < n; i++) {
		ans += x;
	}
	cout << ans << endl;
}