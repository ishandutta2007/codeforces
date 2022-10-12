/**
*    author:  Mohamed Abo Okail
*    created: 14/11/2O21
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

	ll t; cin >> t;
	while(t--) {
		ll n, m; cin >> n >> m;
		if(n < m) swap(n, m);
		ll ans = 0;
		if(n >= 3) {
			ans += n / 3 * m;
			n -= n / 3 * 3;
		}
		if(n < m) swap(n, m);
		if(n >= 3) {
			ans += n / 3 * m;
			n -= n / 3 * 3;
		}
		if(n < m) swap(n, m);
		ans += (n + 2) / 3 * m;
		cout << ans << endl;
	}
}