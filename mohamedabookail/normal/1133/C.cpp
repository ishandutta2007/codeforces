/**
 *    author:  Mohamed Abo_Okail
 *    created: 21/O6/2O2O
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
	vector < int > v;
	map < int, int > mp;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int oo; cin >> oo;
		mp[oo]++;
		if(mp[oo] == 1)
			v.push_back(oo);
	}
	for (int i = 0; i < sz(v); i++) {
		int cnt = 0;
		for (int j = v[i]; j <= v[i] + 5; j++) {
			cnt += mp[j];
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}