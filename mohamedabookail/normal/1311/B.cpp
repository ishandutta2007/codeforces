/**
 *    author:  Mohamed Abo_Okail
 *    created: 24/O2/2O2O
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
		ll n, m; cin >> n >> m;
		vector < ll > v(n), x(n);
		map < ll, bool > mp;
		bool bol = 1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			x[i] = v[i];
		}
		sort(x.begin(), x.end());
		for (int i = 0; i < m; i++) {
			ll oo; cin >> oo;
			mp[oo] = 1;
		}
		while(true) {
			for (int i = 1; i < n; i++) {
				if(v[i] < v[i - 1]) {
					if(mp[i]) {
						swap(v[i], v[i - 1]);				
					}
					else {
						bol = 0;
						break;
					}
				}
			}
			if(!bol) break;
			ll cnt = 0;
			for (int i = 0; i < n; i++) {
				if(v[i] == x[i]) cnt++;
			}
			if(cnt == n) break;
		}
		cout << (bol ? "YES" : "NO") << o_o;
	}
}