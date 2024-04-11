/**
*    author:  Mohamed AboOkail
*    created: 15/12/2O2O
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
		vector < int > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n / 2; i++) {
			cout << a[i] << ' ';
			cout << a[n - i - 1] << ' ';
		}
		if(n & 1) cout << a[n / 2];
		cout << endl;
	}
}