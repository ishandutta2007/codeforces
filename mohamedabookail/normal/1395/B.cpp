/**
*    author:  Mohamed Abo_Okail
*    created: 12/O8/2O2O
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
	return (x / _gcd(x, y) * y);
}
int main() {
	std::ios_base::sync_with_stdio(0);
	ll n, m, x, y; cin >> n >> m >> x >> y;
	bool bol = 1;
	cout << x << ' ' << y << endl;
	for (int i = 1; i < y; i++) {
		cout << x << ' ' << i <<  endl;
	}
	for (int i = x; i <= n; i++) {
		vector < pair < ll , ll > > v;
		for (int j = 1; j <= m; j++) {
			if(i == x && j == y) { }
			else if(i == x && j >= y)
				v.push_back(make_pair(i, j));
			else if(i != x)
				v.push_back(make_pair(i, j));
		}
		if(!bol) reverse(v.begin(), v.end());
		for (int j = 0; j < sz(v); j++) {
			cout << v[j].first << ' ' << v[j].second << endl;
		}
		bol = !bol;
	}
	for (int i = 1; i < x; i++) {
		vector < pair < ll , ll > > v;
		for (int j = 1; j <= m; j++) {
			if(i == x && y == j) break;
			v.push_back(make_pair(i, j));
		}
		if(!bol) reverse(v.begin(), v.end());
		for (int j = 0; j < sz(v); j++) {
			cout << v[j].first << ' ' << v[j].second << endl;
		}
		bol = !bol;
	}
}