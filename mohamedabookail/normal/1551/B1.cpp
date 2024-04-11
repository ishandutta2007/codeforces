/**
*    author:  Mohamed Abo Okail
*    created: 23/O7/2O21
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
		map < char, int > mp;
		for (int i = 0; i < sz(s); i++) {
			mp[s[i]]++;
		}
		int cnt = 0;
		for (auto it : mp) {
			if(it.second > 1) {
				cnt += 2;
			}
			if(it.second == 1) {
				cnt++;
			}
		}
		cout << cnt / 2 << endl;
	}
}