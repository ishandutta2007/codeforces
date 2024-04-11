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
		vector < long long > a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		long long ans = (a[n / 2] - a[n / 2 -1] + 1) * (b[n / 2] - b[n / 2 - 1] + 1);
		cout << ((n & 1) ? 1 : ans) << "\n";
	}
}