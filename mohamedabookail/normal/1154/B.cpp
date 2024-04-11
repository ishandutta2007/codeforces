/**
*    author:  Mohamed AboOkail
*    created: 10/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector < int > a;
	map < int, int > mp;
	for (int i = 0; i < n; i++) {
		int oo;
		cin >> oo;
		mp[oo]++;
		if(mp[oo] == 1) {
			a.push_back(oo);
		}
	}
	sort(a.begin(), a.end());
	if(a.size() == 1) {
		cout << 0 << endl;
	}
	else if(a.size() == 2) {
		cout << ((a[1] - a[0]) % 2 == 0 ? (a[1] - a[0]) / 2 : a[1] - a[0]) << endl;
	}
	else if(a.size() == 3) {
		cout << (a[2] - a[1] == a[1] - a[0] ? a[1] - a[0] : -1) << endl;
	}
	else {
		cout << -1 << endl;
	}
}