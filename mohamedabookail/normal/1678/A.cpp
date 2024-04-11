/**
*    author:  Mohamed Abo Okail
*    created: O8/O5/2O22
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
		int n;
		cin >> n;
		map < ll , ll > mp;
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			mp[x]++;
			ok |= mp[x] > 1;
		}
		if(mp[0]) {
			cout << n - mp[0] << endl;
		}
		else if(ok) {
			cout << n << endl;
		}
		else {
			cout << n + 1 << endl;
		}
	}
}