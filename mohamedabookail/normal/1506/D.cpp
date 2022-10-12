/**
*    author:  Mohamed Abo Okail
*    created: 31/O3/2O21
**/
#include <bits/stdc++.h>

using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		map < ll, ll > mp;
		ll mx = 0;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			mp[oo]++;
			mx = max(mx, mp[oo]);
		}
		cout << (mx >= n - mx ? mx - (n - mx) : (n & 1)) << endl;
	}
}