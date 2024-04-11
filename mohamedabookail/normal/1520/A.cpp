/**
*    author:  Mohamed Abo Okail
*    created: 14/O5/2O21
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
		int n; cin >> n;
		string s; cin >> s;
		bool ok = 1;
		map < int, int > mp;
		int cnt = 1;
		s += '0';
		for (int i = 0; i < n; i++) {
			mp[s[i]]++;
		}
		for (int i = 0; i < n; i++) {
			if(s[i] != s[i + 1]) {
				ok &= (mp[s[i]] == cnt);
				cnt = 1;
			}
			else {
				cnt++;
			}
		}

		cout << (ok ? "YES" : "NO") << endl;
	}
}