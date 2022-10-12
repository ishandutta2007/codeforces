/**
*    author:  Mohamed AboOkail
*    created: 11/01/2O21
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
		int m;
		cin >> m;
		vector < int > b(m);
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		int mx1 = 0, mx2 = 0;
		for (int i = 0; i < n; i++) {
			if(i) a[i] += a[i - 1];
			mx1 = max(mx1, a[i]);
		}
		for (int i = 0; i < m; i++) {
			if(i) b[i] += b[i - 1];
			mx2 = max(mx2, b[i]);
		}
		cout << mx1 + mx2 << "\n";
	}
}