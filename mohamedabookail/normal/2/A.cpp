/**
 *    author:  Mohamed Abo_Okail
 *    created: 17/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector < pair < string, int > > v(n);
	map < string, int > mp, mc;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		mp[v[i].first] += v[i].second;
	}
	for (int i = 0; i < n; i++) {
		mx = max(mx, mp[v[i].first]);
	}
	for (int i = 0; i < n; i++) {
		mc[v[i].first] += v[i].second;
		if(mp[v[i].first] == mx && mc[v[i].first] >= mx) {
			return cout << v[i].first << endl, 0;
		}
	}
}