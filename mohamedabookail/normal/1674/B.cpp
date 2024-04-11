/**
*    author:  Mohamed Abo Okail
*    created: O2/O5/2O22
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
	
	map < string , int > mp;
	int cnt = 1;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			string x = "";
			x += char('a' + i);
			x += char('a' + j);
			if(x[0] != x[1]) {
				mp[x] = cnt++;
			}
		}
	}
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		cout << mp[s] << endl;
	}
}