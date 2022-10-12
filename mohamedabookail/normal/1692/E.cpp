/**
*    author:  Mohamed Abo Okail
*    created: 27/O6/2O22
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n, s; cin >> n >> s;
		vector < int > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int sum = accumulate(all(a), 0);
		if(s > sum) {
			cout << -1 << endl;
			continue;
		}
		vector < int > prfix_S(n + 1, 0), prfix_E(n + 1, 0);
		for (int i = 0; i < n; i++) {
			prfix_S[i + 1] = prfix_S[i] + a[i];
		}
		for (int i = n - 1; i >= 0; i--) {
			prfix_E[n - i] = prfix_E[n - i - 1] + a[i];
		}
		int ans = 1e9;
		s = sum - s;
		for (int i = 0; i <= s; i++) {
			int lo = 0, hi = n, mid = 0, cur1 = 0;
			while(lo <= hi) {
				mid = (lo + hi) / 2;
				if(prfix_S[mid] < i) {
					lo = mid + 1;
				}
				else {
					hi = mid - 1;
					cur1 = mid;
				}
			}
			lo = 0, hi = n, mid = 0;
			int cur2 = 0;
			while(lo <= hi) {
				mid = (lo + hi) / 2;
				if(prfix_E[mid] < s - i) {
					lo = mid + 1;
				}
				else {
					hi = mid - 1;
					cur2 = mid;
				}
			}
			ans = min(ans, cur1 + cur2);
		}
		cout << ans << endl;
	}
}