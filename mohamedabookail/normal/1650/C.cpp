/**
*    author:  Mohamed Abo Okail
*    created: O8/O3/2O22
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
		int n, m; cin >> n >> m;
		vector < pair < ll , pair < ll , ll > > > a(m);
		for (int i = 0; i < m; i++) {
			cin >> a[i].second.first >> a[i].first;
			a[i].second.second = i + 1;
		}
		sort(all(a));
		ll ans = 0;
		vector < pair < ll , ll > > flag(n * 2);
		for (int i = 0; i < n * 2; i++) {
			ans += a[i].first;
			flag[i].first = a[i].second.first;
			flag[i].second = a[i].second.second;
		}
		sort(all(flag));
		cout << ans << endl;
		for (int i = 0; i < n; i++) {
			cout << flag[i].second << ' ' << flag[2 * n - i - 1].second << endl;
		}
	}
}