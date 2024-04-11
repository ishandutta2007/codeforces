/**
*    author:  Mohamed AboOkail
*    created: 14/01/2O21
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
		int n, d;
		cin >> n >> d;
		vector < int > a(n);
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] > d) ok = 0;
		}
		sort(a.begin(), a.end());
		int ans = a[0];
		if(n > 1) ans += a[1];
		cout << (ans <= d || ok ? "YES" : "NO") << endl;
	}
}