/**
*    author:  Mohamed AboOkail
*    created: 25/12/2O2O
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int c1, c2, c3;
		cin >> c1 >> c2 >> c3;
		int a1, a2, a3, a4, a5;
		cin >> a1 >> a2 >> a3 >> a4 >> a5;
		c1 -= a1;
		c2 -= a2;
		c3 -= a3;
		if(c1 < 0 || c2 < 0 || c3 < 0) {
			cout << "NO" << endl;
			continue;
		}
		int cur1 = min(c1, a4);
		c1 -= cur1;
		a4 -= cur1;
		int cur2 = min(c2, a5);
		c2 -= cur2;
		a5 -= cur2;
		cout << (c3 >= (a4 + a5) ? "YES" : "NO") << endl;
	}
}