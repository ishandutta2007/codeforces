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
const int MAXN = 1200;

int n;
ll x[MAXN];
ll y[MAXN];
ll a[MAXN];
ll b[MAXN];

vector<pair<ll, ll>> vv;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vv.emplace_back(x[i] + a[j], y[i] + b[j]);
		}
	}
	sort(vv.begin(), vv.end());
	int cnt = 0;
	for (int i = 0; i < vv.size(); ++i) {
		++cnt;
		if (cnt >= n) {
			cout << vv[i].first << " " << vv[i].second << "\n";
			return 0;
		}
		if (i + 1 == vv.size() || vv[i] != vv[i + 1])
			cnt = 0;
	}
	assert(false);
	return 0;
}