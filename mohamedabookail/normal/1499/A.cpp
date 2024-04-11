/**
*    author:  Mohamed Abo Okail
*    created: 28/O3/2O21
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
		ll n, k1, k2; cin >> n >> k1 >> k2;
		ll w, b; cin >> w >> b;
		ll ans1 = (k1 + k2) / 2;
		ll ans2 = ((n - k1) + (n - k2)) / 2;
		cout << (ans1 >= w && ans2 >= b ? "YES" : "NO") << endl;
	}
}