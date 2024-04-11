/**
*    author:  Mohamed Abo Okail
*    created: 11/1O/2O21
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
		char ch; cin >> ch;
		string s; cin >> s;
		int cnt = 0;
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			cnt += (s[i] == ch);
		}
		if(cnt == n) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < n; i++) {
			if(s[i] == ch && (i + 1) * 2 > n) {
				cout << 1 << endl;
				cout << i + 1 << endl;
				ok = 1;
				break;
			}
		}
		if(!ok) {
			cout << 2 << endl;
			cout << n - 1 << ' ' << n << endl;
		}
	}
}