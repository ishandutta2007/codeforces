/**
*    author:  Mohamed Abo Okail
*    created: 19/O4/2O21
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
		ll n, k; cin >> n >> k;
		ll ans = 1, mod = 1e9 + 7;
		for (int i = 0; i < k; i++) {
			ans = ans * n % mod;
		}
		cout << ans << endl;
	}
}