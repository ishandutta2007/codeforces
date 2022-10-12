/**
 *    author:  Mohamed Abo_Okail
 *    created: O9/O3/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define o_o "\n"
#define ll long long
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		ll n, k; cin >> n >> k;
		vector < ll > v(n);
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if(!v[i]) cnt++;
		}
		if(cnt == n) cout << "YES" << o_o;
		else {
			sort(v.begin(), v.end());
			ll mx = v[n - 1], ans = 0, i = 0;
			vector < ll > x;
			map < ll, ll > mp;
			while(ans < mx) {
				ans = pow(k, i);
				x.push_back(ans);
				i++;
				mp[ans] = 1;
			}
			for (int i = n - 1; i >= 0; i--) {
				for (int j = x.size() - 1; j >= 0; j--) {
					if(v[i] >= x[j] && mp[x[j]]) {
						v[i] -= x[j];
						mp[x[j]] = 0;
					}
				}
			}
			cnt = 0;
			for (int i = 0; i < n; i++) {
				if(!v[i]) cnt++;
			}
			cout << (cnt == n ? "YES" : "NO") << o_o;
		}
	}
}