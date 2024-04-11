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
		int mx = 0, mn = 1e9, sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
			sum += a[i];
		}
		if(mx == mn) {
			cout << 0 << endl;
			continue;
		}
		for (int i = n; i >= 1; i--) {
			if(sum % i) continue;
			int cur = sum / i;
			int summ = 0;
			bool ok = 1;
			for (int j = 0; j < n; j++) {
				summ += a[j];
				if(summ == cur) summ = 0;
				else if(summ > cur) {
					ok = 0;
					break;
				}
			}
			if(ok) {
				cout << n - i << endl;
				break;
			}
		}
	}
}