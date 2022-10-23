/**
*    author:  Mohamed Abo Okail
*    created: 16/1O/2O22
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
		int n;
		cin >> n;
		vector < int > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		string s; cin >> s;
		bool ok = 1;
		map < int , char > mp;
		for (int i = 0; i < n; i++) {
			if(mp[a[i]] && mp[a[i]] != s[i]) {
				ok = 0;
			}
			mp[a[i]] = s[i];
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}