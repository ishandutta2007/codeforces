/**
*    author:  Mohamed Abo Okail
*    created: 24/1O/2O21
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
		string x = s;
		reverse(all(x));
		if(s == x) {
			cout << 0 << endl;
			continue;
		}
		int ans = 1e9;
		for(char ch = 'a'; ch <= 'z'; ch++) {
			int a = 0, b = n - 1, cnt = 0;
			bool ok = 1;
			while(a < b) {
				if(s[a] == s[b]) {
					a++;
					b--;
				}
				else if(s[a] == ch) {
					cnt++;
					a++;
				}
				else if(s[b] == ch) {
					cnt++;
					b--;
				}
				else {
					ok = 0;
					break;
				}
			}
			if(ok) {
				ans = min(ans, cnt);
			}
		}
		cout << (ans != 1e9 ? ans : -1) << endl;
	}
}