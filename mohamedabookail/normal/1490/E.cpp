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
		vector < long long > a(n), b;
		map < long long, int > mp, mpp;
		long long mn = 1e9, mx = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
			if(mp[a[i]] == 1) {
				b.push_back(a[i]);
			}
			mn = min(mn, a[i]);
			mx = max(mx, a[i]);
		}
		if(n == 1) {
			cout << 1 << "\n";
			cout << 1 << "\n";
		}
		else if(mn == mx) {
			cout << n << "\n";
			for (int i = 0; i < n; i++) {
				cout << i + 1 << ' ';
			}
			cout << "\n";
		}
		else {
			sort(b.begin(), b.end());
			long long x = 0, flag = -1;
			for (int i = 0; i < b.size(); i++) {
				if(i == b.size() - 1) {
					mpp[b[i]] = 1;
					break;
				}
				x += mp[b[i]] * b[i];
				if(x >= b[i + 1]) {
					mpp[b[i]] = 1;
				}
				else {
					flag = i;
				}
			}
			for (int i = 0; i <= flag; i++) {
				mpp[b[i]] = 0;
			}
			long long ans = 0;
			for (int i = 0; i < n; i++) {
				ans += mpp[a[i]];
			}
			cout << ans << "\n";
			for (int i = 0; i < n; i++) {
				if(mpp[a[i]]) {
					cout << i + 1 << ' ';
				}
			}
			cout << "\n";
		}
	}
}