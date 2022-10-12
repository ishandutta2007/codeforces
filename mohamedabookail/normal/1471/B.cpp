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
		long long n, x;
		cin >> n >> x;
		vector < long long > a(n);
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ans += a[i];
		}
		int mx = 1e9, idx = 0;
		for (int i = 0; i < n; i++) {
			long long cur = a[i];
			int cnt = 0;
			while(cur % x == 0) {
				cnt++;
				cur /= x;
			}
			if(cnt < mx) {
				mx = cnt;
				idx = i;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < mx + (i < idx); j++) {
				ans += a[i];
			}
		}
		cout << ans << "\n";
	}
}