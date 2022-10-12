/**
*    author:  Mohamed Abo Okail
*    created: 31/O3/2O22
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
		ll n;
		cin >> n;
		if(n & 1) {
			cout << 0 << endl;
			continue;
		}
		ll ans = 1;
		ll mod = 998244353;
		for (int i = 1; i <= n / 2; i++) {
			ans *= i;
			ans %= mod;
		}
		cout << ans * ans % mod << endl;
	}
}