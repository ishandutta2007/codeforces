/**
*    author:  Mohamed Abo Okail
*    created: 1O/O6/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector < ll > a(n);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if(sum % n) {
			cout << -1 << endl;
			continue;
		}
		ll cur = sum / n, ans = 0;
		for (int i = 0; i < n; i++) {
			ans += a[i] > cur;
		}
		cout << ans << endl;
	}
}