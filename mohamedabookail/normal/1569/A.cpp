/**
*    author:  Mohamed Abo Okail
*    created: 10/O9/2O21
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
		for (int i = 0; i < n - 1; i++) {
			if(s[i] != s[i + 1]) {
				cout << i + 1 << ' ' << i + 2 << endl;
				ok = 1;
				break;
			}
		}
		if(!ok) cout << "-1 -1" << endl;
	}
}