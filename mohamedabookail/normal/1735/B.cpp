/**
*    author:  Mohamed Abo Okail
*    created: O4/1O/2O22
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
		int n;
		cin >> n;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(all(a));
		ll ans = 0;
		for (int i = n - 1; i > 0 ; i--) {
			ans += (a[i] / (a[0] * 2 - 1)) - 1;
			ans += (a[i] % (a[0] * 2 - 1) != 0);
		}
		cout << ans << endl;
	}
}