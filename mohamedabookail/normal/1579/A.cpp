/**
*    author:  Mohamed Abo Okail
*    created: 30/O9/2O21
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
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < sz(s); i++) {
			a += (s[i] == 'A');
			b += (s[i] == 'B');
			c += (s[i] == 'C');
		}
		cout << (a + c == b ? "YES" : "NO") << endl;
	}
}