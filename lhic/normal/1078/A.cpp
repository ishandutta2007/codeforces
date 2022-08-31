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


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

#define y1 y1_asdf

ll a, b, c;
ll x1, y1, x2, y2;

ld dist(pair<ld, ld> a, pair<ld, ld> b) {
	ld x = a.first - b.first;
	ld y = a.second - b.second;
	return sqrt(x * x + y * y);
}

vector<pair<ld, ld>> get(ll a, ll b, ll c, ll x, ll y) {
	vector<pair<ld, ld>> ans;
	if (b != 0)
		ans.emplace_back(x, (-c - a * x) / ld(b));
	if (a != 0)
		ans.emplace_back((-c - b * y) / ld(a), y);
	return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(20);
	cin >> a >> b >> c;
	cin >> x1 >> y1 >> x2 >> y2;
	ld ans = abs(x1 - x2) + abs(y1 - y2);
	vector<pair<ld, ld>> v1 = get(a, b, c, x1, y1);
	vector<pair<ld, ld>> v2 = get(a, b, c, x2, y2);
	for (auto x: v1)
		for (auto y: v2) {
			ans = min(ans, dist(x, y) + dist(make_pair(x1, y1), x) + dist(make_pair(x2, y2), y));
		}
	cout << ans << "\n";
	return 0;
}