/**
*    author:  Mohamed Abo Okail
*    created: 12/11/2O21
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
		for (int i = 1; i < 10; i++) {
			for (int j = i; j < n; j++) {
				int a = 0, b = 0, c = 0;
				for (int k = j; k >= j - i ; k--) {
					a += (s[k] == 'a');
					b += (s[k] == 'b');
					c += (s[k] == 'c');
				}
				if(a > b && a > c) {
					cout << i + 1 << endl;
					ok = 1;
					break;
				}
			}
			if(ok) break;
		}
		if(!ok) cout << -1 << endl;
	}
}