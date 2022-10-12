/**
*    author:  Mohamed Abo Okail
*    created: 29/O7/2O21
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
		int n, k; cin >> n >> k;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll ans = -1e18;
		for (int i = n - 1; i >= max(0, n - 205); i--) {
			for (int j = n - 1; j >= max(0, n - 205); j--) {
				if(i == j) continue;
				ans = max(ans, 1LL * (i + 1) * (j + 1) - k * (a[i] | a[j]));
			}
		}
		cout << ans << endl;
	}
}