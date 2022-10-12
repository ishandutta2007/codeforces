/**
 *    author:  Mohamed Abo_Okail
 *    created: 22/O6/2O2O
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
	int n, k; string s; cin >> n >> k >> s;
	map < char, bool > mp;
	vector < ll > v;
	ll cnt = 0, ans = 0;
	s += '0';
	for (int i = 0; i < k; i++) {
		char ch; cin >> ch;
		mp[ch] = 1;
	}
	for (int i = 0; i < sz(s); i++) {
		if(mp[s[i]]) ans ++, cnt ++;
		else if(cnt) v.push_back(cnt), cnt = 0;
	}
	for (int i = 0; i < sz(v); i++) {
		ans += v[i] * (v[i] - 1) / 2;
	}
	cout << ans << endl;
}