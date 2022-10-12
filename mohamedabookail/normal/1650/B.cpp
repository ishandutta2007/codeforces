/**
*    author:  Mohamed Abo Okail
*    created: O8/O3/2O22
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
		ll l, r, a;
		cin >> l >> r >> a;
		ll ans = (r / a) + (r % a);
		ll cur = (r / a) * a - 1;
		if(cur >= l) {
			ans = max(ans, (cur / a) + (cur % a));
		}
		cout << ans << endl;
	}
}