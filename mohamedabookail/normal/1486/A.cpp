/**
*    author:  Mohamed AboOkail
*    created: 18/02/2O21
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
		vector < long long > a(n);
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i < n; i++) {
			if(a[i - 1] > i - 1) {
				a[i] += a[i - 1] - (i - 1);
			}
			if(a[i] < i) ok = 0;
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
}