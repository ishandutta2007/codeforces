#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long long llong;
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
const int MX = 500000;

int goul[MX];
int godl[MX];
int godr[MX];
int gour[MX];

ll solve(vector<pair<int, int>> vv) {
	if (vv.empty())
		return 0;
	int mnx = 1e8;
	int mny = 1e8;
	for (int i = 0; i < vv.size(); ++i) {
		vv[i] = make_pair(vv[i].first - vv[i].second, vv[i].first + vv[i].second);
		vv[i] = make_pair((vv[i].first + 1) / 2, (vv[i].second + 1) / 2);
		mnx = min(mnx, vv[i].first);
		mny = min(mny, vv[i].second);
	}
	for (int i = 0; i < vv.size(); ++i)
		vv[i].first -= mnx, vv[i].second -= mny;
	for (int i = 0; i < MX; ++i)
		goul[i] = -1, gour[i] = -1, godl[i] = godr[i] = MX;
	for (int i = 0; i < vv.size(); ++i) {
		int x, y;
		tie(x, y) = vv[i];
		godl[x] = min(godl[x], y);
		goul[x] = max(goul[x], y - 1);
		if (x) {
			godr[x - 1] = min(godr[x - 1], y);
			gour[x - 1] = max(gour[x - 1], y - 1);
		}
	}
	for (int i = 1; i < MX; ++i) {
		godl[i] = min(godl[i], godl[i - 1]);
		goul[i] = max(goul[i], goul[i - 1]);
	}
	for (int i = MX - 2; i >= 0; --i) {
		godr[i] = min(godr[i], godr[i + 1]);
		gour[i] = max(gour[i], gour[i + 1]);
	}
	ll ans = 0;
	for (int i = 0; i < MX; ++i) {
		int l = max(godl[i], godr[i]);
		int r = min(goul[i], gour[i]);
		if (l <= r)
			ans += (r - l + 1);
	}
	return ans;
}



int n;
int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	vector<pair<int, int> > vv[2];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if ((x + y) % 2 == 0) {
			vv[0].push_back(make_pair(x + 1, y));
		}
		else {
			vv[1].push_back(make_pair(x, y));
		}
	}
	cout << solve(vv[0]) + solve(vv[1]) << "\n";
	return 0;
}