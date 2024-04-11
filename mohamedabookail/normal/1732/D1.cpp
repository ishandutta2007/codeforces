/**
*    author:  Mohamed Abo Okail
*    created: 23/1O/2O22
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
	
	ll q; cin >> q;
	map < ll , bool > mp;
	map < ll , ll > ans;
	ll mex = 1;
	while(q--) {
		char ch;
		ll k;
		cin >> ch >> k;
		if(ch == '+') {
			mp[k] = 1;
			while(mp[mex]) {
				mex++;
			}
		}
		else {
			if(!mp[ans[k]] && ans[k]) {
				cout << ans[k] << endl;
				continue;
			}
			ll start = (mex + k - 1) / k * k;
			if(ans[k]) {
				start = max(start, ans[k] + k);
			}
			for (ll i = start; ; i += k) {
				if(!mp[i]) {
					cout << i << endl;
					ans[k] = i;
					break;
				}
			}
		}
	}
}