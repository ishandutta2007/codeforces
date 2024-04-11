/**
*    author:  Mohamed Abo Okail
*    created: 29/1O/2O21
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
		int a = 0, b = 0;
		for (int i = 0; i < sz(s) - 1; i++) {
			a += (s[i] == 'a' && s[i + 1] == 'b');
			b += (s[i] == 'b' && s[i + 1] == 'a');
		}
		if(a == b) {
			cout << s << endl;
			continue;
		}
		else if(a > b) {
			s[0] = 'b';
			cout << s << endl;
		}
		else {
			s[0] = 'a';
			cout << s << endl;
		}
	}
}