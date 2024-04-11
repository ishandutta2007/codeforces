/**
*    author:  Mohamed Abo Okail
*    created: 15/O8/2O21
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
		int indx = -1;
		for (int i = 0; i < n; i++) {
			if(s[i] != '?') {
				indx = i;
				break;
			}
		}
		if(indx == -1) {
			for (int i = 0; i < n; i++) {
				if(i & 1) {
					s[i] = 'B';
				}
				else {
					s[i] = 'R';
				}
			}
		}
		else {
			for (int i = indx + 1; i < n; i++) {
				if(s[i] == '?') {
					if(s[i - 1] == 'B') {
						s[i] = 'R';
					}
					else {
						s[i] = 'B';
					}
				}
			}
			for (int i = indx - 1; i >= 0; i--) {
				if(s[i] == '?') {
					if(s[i + 1] == 'B') {
						s[i] = 'R';
					}
					else {
						s[i] = 'B';
					}
				}
			}
		}
		cout << s << endl;
	}
}