/**
 *    author:  Mohamed Abo_Okail
 *    created: 19/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		ll n, s, k;
		cin >> n >> s >> k;
		map <ll, ll> mp;
		ll ans1 = 0, ans2 = 0;
		bool b1 = 0, b2 = 0;
		for (int i = 0; i < k; i++)	{
			ll a; cin >> a;
			mp[a]++;
		}
		for (int i = s; i <= n; i++) {
			if(mp[i] != 0) { ans1++; }
			else {
				b1 = 1;
				break; 
			}
		}
		for (int i = s; i > 0; i--) {
			if(mp[i] != 0) { ans2++; }
			else {
				b2 = 1;
				break;
			}
		}
		if(b1 && b2) {
			cout << min(ans1, ans2) << endl;
		}
		else if(b1) {
			cout << ans1 << endl;
		}
		else {
			cout << ans2 << endl;
		} 
	}
}