/**
*    author:  Mohamed Abo Okail
*    created: 22/O3/2O22
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
		ll n, b, x, y;
		cin >> n >> b >> x >> y;
		vector < ll > a(n + 1);
		a[0] = 0;
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			if(x + a[i - 1] <= b) {
				a[i] = x + a[i - 1];
			}
			else {
				a[i] = a[i - 1] - y;
			}
			ans += a[i];
		}
		cout << ans << endl;
	}
}