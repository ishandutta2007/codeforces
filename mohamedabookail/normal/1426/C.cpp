/**
*    author:  Mohamed Abo_Okail
*    created: 28/O9/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll ans = 2e9, cur = 0, mx = 0;
		for (ll i = 1; i <= 100000; i++) {
			mx++;
			ll flag = n - mx;
			if(flag < 0) break;
			cur = mx + ((flag + mx - 1) / mx);
			ans = min(ans, cur);
		}
		cout << ans - 1 << endl;
	}
}