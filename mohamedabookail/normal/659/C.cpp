/**
*    author:  Mohamed Abo_Okail
*    created: 24/O6/2O2O
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
	int n, m; cin >> n >> m;
	map < int, bool > mp;
	vector < int > v;
	int flag = 1;
	for (int i = 0; i < n; i++) {
		int oo; cin >> oo;
		mp[oo] = 1;
	}
	while(m) {
		if(!mp[flag] && m < flag) break;
		if(!mp[flag]) v.push_back(flag), m -= flag;
		flag ++;
	}
	cout << v.size() << endl;
	for (int i = 0; i < sz(v); i++) {
		cout << v[i];
		if(i != sz(v) - 1) cout << ' ';
	}
}