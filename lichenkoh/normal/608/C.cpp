#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin >> n;
	pair<ll,ll> *c = new pair<ll,ll>[n];
	for (ll i = 0; i < n; i++) {
		ll a,b; cin >> a >>b;
		c[i] = MP(a,b);
	}
	sort(c,c+n);
	map<ll,ll, greater<ll> > h;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll a = c[i].first; ll b = c[i].second;
		auto it = h.lower_bound(a-b-1);
		ll x = 0;
		if (it != h.end()) {
			x = it->second;
		}
		x++;
		h[a] = x;
		ans = max(ans, x);
	}
	ll final = n - ans;
	cout << final << endl;
}