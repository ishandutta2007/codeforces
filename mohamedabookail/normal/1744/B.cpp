/**
*    author:  Mohamed Abo Okail
*    created: 16/1O/2O22
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
		ll n, q;
		cin >> n >> q;
		vector < ll > a(n);
		ll ans = 0, even = 0, odd = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ans += a[i];
			even += (a[i] % 2 == 0);
			odd += (a[i] % 2);
		}
		while(q--) {
			ll t, x;
			cin >> t >> x;
			if(t == 0) {
				ans += even * x;
				if(x & 1) {
					odd += even;
					even = 0;
				}
			}
			else {
				ans += odd * x;
				if(x & 1) {
					even += odd;
					odd = 0;
				}
			}
			cout << ans << endl;
		}
	}
}