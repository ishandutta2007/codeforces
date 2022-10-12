/**
*    author:  Mohamed Abo Okail
*    created: 17/O4/2O22
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
		int n, a, b;
		cin >> n >> a >> b;
		vector < ll > ar(n);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		ll ans = b * ar[0] + a * ar[0];
		for (int i = 1; i < n; i++) {
			ans += b * abs(ar[i] - ar[0]);
		}
		for (int i = 1; i < n; i++) {
			if(a * abs(ar[i] - ar[i - 1]) < abs(ar[i] - ar[i - 1]) * (n - i - 1) * b) {
				ans += a * abs(ar[i] - ar[i - 1]);
				ans -= abs(ar[i] - ar[i - 1]) * (n - i - 1) * b;
			}
			else {
				break;
			}
		}
		if(a * ar[0] > ar[0] * (n - 1) * b) {
			ans -= a * ar[0];
			ans += ar[0] * (n - 1) * b;
		}
		cout << ans << endl;
	}
}