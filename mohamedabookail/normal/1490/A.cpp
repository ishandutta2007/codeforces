/**
*    author:  Mohamed AboOkail
*    created: 16/02/2O21
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
		long long ans = 0;
		for (int i = 1; i < n; i++) {
			long long mx = max(a[i], a[i - 1]);
			long long mn = min(a[i], a[i - 1]);
			if(mn * 2 >= mx) continue;
			while(mn * 2 < mx) {
				mn *= 2;
				ans++;
			}
		}
		cout << ans << "\n";
	}
}