/**
*    author:  Mohamed Abo Okail
*    created: 21/O4/2O22
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
		map < ll , ll > mp;
		ll ans = -1, x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			mp[x]++;
			if(mp[x] > 2) {
				ans = x;
			}
		}
		cout << ans << endl;
	}
}