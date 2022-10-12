/**
*    author:  Mohamed AboOkail
*    created: 11/02/2O21
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
		long long n, k;
		cin >> n >> k;
		vector < long long > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long ans = -1;
		while(k--) {
			bool ok = 1;
			for (int i = 0; i < n - 1; i++) {
				if(a[i] >= a[i + 1] && i + 1 == n - 1) {
					ok = 0;
					ans = -1;
					break;
				}
				if(a[i] < a[i + 1]) {
					a[i]++;
					ans = i + 1;
					break;
				}
			}
			if(!ok) break;
		}
		cout << ans << "\n";
	}
}