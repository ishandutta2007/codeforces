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
		map < int, int > mp;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
			mx = max(mx, a[i]);
		}
		long long ans = 0;
		map < int, bool > mpx;
		for (int i = 1; i <= mx; i++) {
			long long cur = mp[i] + mp[i + 1] + mp[i + 2];
			if(cur >= 3) {
				ans += (cur * (cur - 1) * (cur - 2)) / 6;
			}
			if(mpx[i] && mpx[i + 1]) {
				long long curr = mp[i] + mp[i + 1];
				ans -= (curr * (curr - 1) * (curr - 2)) / 6;
			}
			mpx.clear();
			mpx[i + 1] = 1;
			mpx[i + 2] = 1;
		}
		cout << ans << endl;
	}
}