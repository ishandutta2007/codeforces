/**
*    author:  Mohamed Abo_Okail
*    created: 25/O6/2O2O
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
	vector < pair < int, int > > v(n);
	vector < int > flag;
	ll sum = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		sum += v[i].first;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
	mx = v[n - 1].first;
	for (int i = 0; i < n; i++) {
		if(i == n - 1) mx = v[n - 2].first;
		sum -= v[i].first;
		if(sum == mx * 2) flag.push_back(v[i].second);
		sum += v[i].first;
	}
	cout << sz(flag) << endl;
	for (int i = 0; i < sz(flag); i++) {
		cout << flag[i];
		if(i != sz(flag) - 1) cout << ' ';
	}
}