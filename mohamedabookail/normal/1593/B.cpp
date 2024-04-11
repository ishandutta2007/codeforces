/**
*    author:  Mohamed Abo Okail
*    created: 19/1O/2O21
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
		int ans = 1e2;
		reverse(all(s));
		string a = "52", b = "05", c = "57", d = "00";
		for (int i = 0; i < sz(s); i++) {
			int indx1 = 0, indx2 = 0, indx3 = 0, indx4 = 0;
			for (int j = i; j < sz(s); j++) {
				if(indx1 < 2 && a[indx1] == s[j]) {
					indx1++;
					if(indx1 == 2) {
						ans = min(ans, j - 1);
					}
				}
				if(indx2 < 2 && b[indx2] == s[j]) {
					indx2++;
					if(indx2 == 2) {
						ans = min(ans, j - 1);
					}
				}
				if(indx3 < 2 && c[indx3] == s[j]) {
					indx3++;
					if(indx3 == 2) {
						ans = min(ans, j - 1);
					}
				}
				if(indx4 < 2 && d[indx4] == s[j]) {
					indx4++;
					if(indx4 == 2) {
						ans = min(ans, j - 1);
					}
				}
			}
		}
		cout << ans << endl;
	}
}