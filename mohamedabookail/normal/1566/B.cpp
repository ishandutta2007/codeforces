/**
*    author:  Mohamed Abo Okail
*    created: 13/O9/2O21
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
		for (int i = 0; i < sz(s); i++) {
			a += (s[i] == '0');
			b += (s[i] == '1');
		}
		if(a == sz(s)) {
			cout << 1 << endl;
		}
		else if(b == sz(s)) {
			cout << 0 << endl;
		}
		else {
			int cnt = 0;
			for (int i = 0; i < sz(s); i++) {
				if(s[i] == '0') cnt++;
				if(s[i] == '1' && cnt) break;
			}
			cout << (cnt == a ? 1 : 2) << endl;
		}
	}
}