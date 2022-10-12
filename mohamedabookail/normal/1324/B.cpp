/**
 *    author:  Mohamed Abo_Okail
 *    created: 12/O3/2O2O
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
		ll n; cin >> n;
		vector < ll > v(n);
		map < ll, ll > mp;
		bool bol = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mp[v[i]]++;
			if(mp[v[i]] >= 3) bol = 1;
		}
		if(bol) cout << "YES";
		else {
			for (int i = 0; i < n - 1; i++) {
				if(mp[v[i]] == 2) {
					if(v[i + 1] != v[i]) {
						bol = 1;
						break;
					}
					else mp[v[i]]--;
				} 
			}
			cout << (bol ? "YES" : "NO");
		}
		cout << o_o;
	}
}