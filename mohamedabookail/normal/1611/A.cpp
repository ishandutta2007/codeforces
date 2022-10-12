/**
*    author:  Mohamed Abo Okail
*    created: 25/11/2O21
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
		if((s.back() - '0') % 2 == 0) {
			cout << 0 << endl;
		}
		else if((s[0] - '0') % 2 == 0) {
			cout << 1 << endl;
		}
		else {
			int cnt = -1;
			for (int i = 0; i < sz(s); i++) {
				if((s[i] - '0') % 2 == 0) {
					cnt = 2;
					break;
				}
			}
			cout << cnt << endl;
		}
	}
}