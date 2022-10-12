/**
*    author:  Mohamed AboOkail
*    created: 11/12/2O2O
**/
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		char ch = 'a';
		for (int i = 0; i < n; i++) {
			cout << char(ch + (i % 3));
		}
		cout << endl;
	}
}