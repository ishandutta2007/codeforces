/**
*    author:  Mohamed Abo Okail
*    created: 2O/O5/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int cnt = 0;
		for (int i = 0; i < sz(s); i++) {
			cnt += s[i] == 'a';
		}
		if(cnt == sz(s)) {
			cout << "NO" << endl;
			continue;
		}
		for (int i = 0; i < sz(s); i++) {
			if(s[i] == s[sz(s) - i - 1] && s[i] == 'a') continue;
			if(s[i] == 'a') s.insert(i, "a");
			else if(s[sz(s) - i - 1] == 'a') s.insert(sz(s) - i - 1, "a");
			else s.insert(i, "a");
			break;
		}
		cout << "YES" << endl << s << endl;
	}
}