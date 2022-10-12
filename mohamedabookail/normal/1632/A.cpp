/**
*    author:  Mohamed Abo Okail
*    created: O1/O2/2O22
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
		int n; cin >> n;
		string s; cin >> s;
		bool ok = 0;
		if(n == 1) {
			ok = 1;
		}
		if(n == 2) {
			ok |= (s[0] != s[1]);
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}