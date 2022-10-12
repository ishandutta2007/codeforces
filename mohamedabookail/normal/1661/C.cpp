/**
*    author:  Mohamed Abo Okail
*    created: O9/O4/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

ll ok(ll even, ll odd) {
	ll ans = 0;
	if(even == odd) {
		ans = even + odd;
	}
	else if(even > odd) {
		ans = odd * 2;
		even -= odd;
		even *= 2;
		ans += (even + 1) / 3 * 2;
		ans += (even % 3 == 1);
	}
	else {
		if(even + 1 == odd) {
			ans = even + odd;
		}
		else {
			ans = odd * 2 - 1;
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector < ll > a(n);
		ll mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		ll even = 0, odd = 0;
		for (int i = 0; i < n; i++) {
			ll x = mx - a[i];
			even += x / 2;
			odd += x % 2;
		}
		ll res = ok(even, odd);
		even = odd = 0;
		mx++;
		for (int i = 0; i < n; i++) {
			ll x = mx - a[i];
			even += x / 2;
			odd += x % 2;
		}
		res = min(res, ok(even, odd));
		cout << res << endl;
	}
}