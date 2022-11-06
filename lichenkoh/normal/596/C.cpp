#include <bits/stdc++.h>
#include <complex>
#include <assert.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define INF 99999999999999999LL
bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
	ll as = a.first + a.second;
	ll bs = b.first + b.second;
	if (as == bs) {
		return a < b;
	}
	else {
		return (as < bs);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	pair<ll,ll> *p = new pair<ll,ll>[n];
	unordered_map<ll, set<pair<pair<ll,ll>,ll> > > h;
	ll *v = new ll[n];
	for (ll i = 0; i < n; i++) {
		ll x,y;
		cin >> x; cin >> y;
		p[i] = MP(x,y);
	}
	sort(p, p+n, cmp);

	for (ll i = 0; i < n; i++) {
		ll x = p[i].first; ll y = p[i].second;
		h[y-x].insert(MP(MP(x,y),i));
	}
	bool bad = false;
	vector<pair<ll,ll> > sol;
	for (ll i = 1; i <= n; i++) {
		ll w; cin >> w;
		if (h[w].size() == 0) {
			bad = true; break;
		}
		ll k = (h[w].begin())->second;
		h[w].erase(h[w].begin());
		v[k] = i;
		sol.PB(p[k]);
	}
	if (bad) {
		cout << "NO" << endl; return 0;
	}
	bad = false;
	map<pair<ll,ll>, ll> dp;
	for (ll i = 0; i < n; i++) {
		ll x = p[i].first; ll y = p[i].second;
		ll ans = -INF;
		if (x-1 >= 0) {
			ans = max(ans, dp[MP(x-1,y)]);
		}
		if (y-1 >= 0) {
			ans = max(ans, dp[MP(x,y-1)]);
		}
		ll k = v[i];
		if (k < ans) {
			bad = true; break;
		}
		ans = max(ans, k);
		dp[MP(x,y)] = ans;
	}
	if (bad) {
		cout << "NO" << endl; return 0;
	}
	else {
		//cout << "YES" << endl;
		printf("YES\n");
		for (auto& y: sol) {
			printf("%I64d %I64d\n", y.first, y.second);
			//cout << y.first << " " << y.second << endl;
		}
	}
}