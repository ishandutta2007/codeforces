/**
 *    author:  Mohamed Abo_Okail
 *    created: 14/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) ll(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector < int > v(n + 1), ans(1e6 + 5), flag;
	map < int, int > mp, mc;
	int ind = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		mp[v[i]] = i + 1;
	}
	for (int i = 1; i <= n; i++) {
		if(mp[v[i]]) mc[mp[v[i]]] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if(!mc[i]) flag.push_back(i);
	}
	for (int i = 0; i <= 1e6; i++) {
		if(mp[i]) ans[mp[i]] = i;
		else {
			if(ind == flag.size()) break;
			ans[flag[ind]] = i;
			ind++;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i];
		if(i != n) cout << ' ';
	}
	cout << endl;
}