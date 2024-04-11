/**
*    author:  Mohamed Abo Okail
*    created: 21/O7/2O22
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
	
	ll t; cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int cnt = 0;
		cnt += (s[0] == 'Y' || s[0] == 'y');
		cnt += (s[1] == 'E' || s[1] == 'e');
		cnt += (s[2] == 'S' || s[2] == 's');
		cout << (cnt == 3 ? "YES" : "NO") << endl;
	}
}