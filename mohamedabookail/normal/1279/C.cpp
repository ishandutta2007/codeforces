/**
 *    author:  Mohamed.Abo_Okail
 *    created: 28/12/2019
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
		ll n, m;
		cin >> n >> m;
		vector <ll> v(n);
		map <ll, ll> mp;
		ll ans = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mp[v[i]] = i;
		}
		for (int i = 0; i < m; i++) {
			ll a; cin >> a;
			if(mp[a] > cnt) {
				ans += (mp[a] - i) * 2 + 1;
				cnt = mp[a];
			}
			else {
				ans++;
			}
		}
		cout << ans << endl;
	}
}