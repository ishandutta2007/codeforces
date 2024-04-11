 /**
*    author:  Mohamed Abo Okail
*    created: 26/11/2O21
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
		int n; cin >> n;
		vector < pair < ll , ll > > a(n);
		vector < ll > ans(n + 1), aa(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i + 1;
			aa[i] = a[i].first;
		}
		sort(all(a));
		ll l = 1, r = n + 1, cur = n / 2 + 1;
		ans[0] = cur;
		for (int i = 0; i < n; i++) {
			if(i & 1) {
				ans[a[i].second] = l;
				l++;
			}
			else {
				ans[a[i].second] = r;
				r--;
			}
		}
		ll res = 0;
		for (int i = 1; i <= n; i++) {
			res += abs(ans[i] - cur) * aa[i - 1] * 2;
		}
		cout << res << endl;
		for (int i = 0; i <= n; i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}