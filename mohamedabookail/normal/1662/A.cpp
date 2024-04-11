/**
*    author:  Mohamed Abo Okail
*    created: 24/O4/2O22
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
		int n; cin >> n;
		map < ll , ll > mp;
		for (int i = 0; i < n; i++) {
			ll a, b; cin >> a >> b;
			mp[b] = max(mp[b], a);
		}
		bool ok = 1;
		ll sum = 0;
		for (int i = 1; i <= 10; i++) {
			ok &= (mp[i] > 0);
			sum += mp[i];
		}
		if(ok) {
			cout << sum << endl;
		}
		else {
			cout << "MOREPROBLEMS" << endl;
		}
	}
}