/**
*    author:  Mohamed Abo Okail
*    created: 22/O1/2O22
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

	int t;
	cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector < pair < ll , ll > > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i].second;
		}
		sort(all(a));
		ll ans = k;
		for (int i = 0; i < n; i++) {
			if(ans >= a[i].first) {
				ans += a[i].second;
			} 
			else {
				break;
			}
		}
		cout << ans << endl;
	}
}