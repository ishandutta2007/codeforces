/**
 *    author:  Mohamed Abo_Okail
 *    created: 12/O6/2O2O
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
	int t; cin >> t;
	while(t --) {
	  ll n, m, x; cin >> n >> x >> m;
	  vector < pair < ll, ll > > v;
	  while(m --) {
	    ll l, r; cin >> l >> r;
	    bool bol = 0;
	    if(x >= l && x <= r) bol = 1;
	    for (int i = 0; i < v.size(); i++) {
	      if(v[i].first >= l && v[i].first <= r) bol = 1;
	      if(v[i].second >= l && v[i].second <= r) bol = 1;
	    }
		if(bol) v.push_back(make_pair(l, r));
	  }
	  ll mn = 1e9, mx = 0;
	  for (int i = 0; i < v.size(); i++) {
	    mn = min(mn, v[i].first);
	    mx = max(mx, v[i].second);
	  }
	  cout << max(mx - mn + 1, 1LL) << endl;
	}
}