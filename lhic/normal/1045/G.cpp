#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>,
		null_type,
		less<>,
		rb_tree_tag,
		tree_order_statistics_node_update>
		mset;

//find_by_order(k);
//order_of_key(x);

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int n, k;

vector<tuple<ll, ll, ll>> vv;

map<int, mset> mm;
vector<int> dl[120000];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		ll x, r, q;
		cin >> x >> r >> q;
		vv.emplace_back(x, r, q);
	}
	sort(vv.begin(), vv.end());
	ll ans = 0;
	for (int i = 0; i < vv.size(); ++i) {
		int x, r, q;
		tie(x, r, q) = vv[i];
		for (int a: dl[i]) {
			int x, r, q;
			tie(x, r, q) = vv[a];
			mm[q].erase({x, a});
		}
		int go = lower_bound(ALL(vv), make_tuple(x + r + 1, 0, 0)) - vv.begin();
		dl[go].push_back(i);
		auto it = mm.lower_bound(q - k);
		while (it != mm.end() && it->first <= q + k) {
			auto it2 = it->second.lower_bound(make_pair(x - r, 0));
			if (it2 != it->second.end())
				ans += it->second.size() - it->second.order_of_key(*it2);
			++it;
		}
		mm[q].insert({x, i});
	}
	cout << ans << "\n";
	return 0;
}