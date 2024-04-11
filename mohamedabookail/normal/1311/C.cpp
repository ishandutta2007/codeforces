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
		ll n, m; string s; cin >> n >> m >> s;
		map < int, ll > mp, cnt;
		vector < vector < ll > > v((n), vector < ll > (27));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				v[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			v[i][s[i] - 'a']++;
			mp[s[i] - 'a']++;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				v[i][j] += v[i - 1][j];
			}
		}
		for (int i = 0; i < m; i++) {
			ll oo; cin >> oo;
			for (int j = 0; j < 26; j++) {
				cnt[j] += v[oo - 1][j];
			}
		}
		for (int i = 0; i < 26; i++) {
			cout << cnt[i] + mp[i] << ' ';
		}
		cout << o_o;
	}
}