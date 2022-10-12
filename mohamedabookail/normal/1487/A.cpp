/**
*    author:  Mohamed AboOkail
*    created: 15/02/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		map < int, int > mp;
		int mn = 1e9;
		for (int i = 0; i < n; i++) {
			int oo;
			cin >> oo;
			mp[oo]++;
			mn = min(mn, oo);
		}
		cout << n - mp[mn] << "\n";
	}
}