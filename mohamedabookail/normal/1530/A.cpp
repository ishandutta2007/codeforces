/**
*    author:  Mohamed Abo Okail
*    created: 06/O8/2O21
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
		ll n; cin >> n;
		ll ans = 1;
		while(n) {
			ans = max(ans, n % 10);
			n /= 10;
		}
		cout << ans << endl;
	}

}