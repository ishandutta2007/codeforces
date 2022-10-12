/**
*    author:  Mohamed AboOkail
*    created: O6/12/2O2O
**/
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector < pair < int , int > > pr(n);
		for (int i = 0; i < n; i++) {
			cin >> pr[i].first >> pr[i].second;
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
			ans = 1;
			for (int j = 0; j < n; j++) {
				int cur = abs(pr[i].first - pr[j].first) + abs(pr[i].second - pr[j].second);
				if(cur > k) {
					ans = -1;
					break;
				}
			}
			if(ans == 1) break;
		}
		cout << ans << endl;
	}
}