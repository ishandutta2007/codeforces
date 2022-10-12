/**
*    author:  Mohamed Abo Okail
*    created: 19/O9/2O22
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
		ll n;
		cin >> n;
		ll ans = n;
		ans += ((n / 2) + ((n / 3) + 1) / 2) * 2;
		ans += (n / 6) * 2;
		cout << ans << endl;
	}
}