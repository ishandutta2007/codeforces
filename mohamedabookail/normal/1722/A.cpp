/**
*    author:  Mohamed Abo Okail
*    created: 18/O9/2O22
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
		string s; cin >> s;
		map < char , bool > mp;
		for (int i = 0; i < n; i++) {
			mp[s[i]] = 1;
		}
		cout << (n == 5 && mp['T'] && mp['i'] && mp['m'] && mp['u'] && mp['r'] ? "YES" : "NO") << endl;
	}
}