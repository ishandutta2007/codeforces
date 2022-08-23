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

int gcd(int a, int b) {
	while (b) {
		ll q = a % b;
		a = b;
		b = q;
	}
	return a;
}

const int MAXN = 210000;

vector<pair<int, int>> vv;

map<ll, vector<pair<int, int> > > mm;

int q;
int t[MAXN];
int x[MAXN];
int y[MAXN];
int cc[MAXN];

void add(int x, int y, int d) {
	int g = gcd(x, y);
	x /= g, y /= g;
	int xx = lower_bound(vv.begin(), vv.end(), make_pair(x, y)) - vv.begin();
	if (xx != vv.size() && vv[xx].first == x && vv[xx].second == y) {
		cc[xx] += d;
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> t[i] >> x[i] >> y[i];
		if (t[i] == 3) {
			int g = gcd(x[i], y[i]);
			x[i] /= g;
			y[i] /= g;
			vv.emplace_back(x[i], y[i]);
		}
	}
	sort(vv.begin(), vv.end());
	vv.resize(unique(ALL(vv)) - vv.begin());
	int cur = 0;
	for (int i = 0; i < q; ++i) {
		ll d = ll(x[i]) * x[i] + ll(y[i]) * y[i];
		if (t[i] == 1) {
			++cur;
			auto &v = mm[d];
			v.emplace_back(x[i], y[i]);
			add(x[i], y[i], 1);
			for (int j = 0; j + 1 < v.size(); ++j)
				add(v[j].first + x[i], v[j].second + y[i], 2);
		}
		else if (t[i] == 2) {
			--cur;
			auto &v = mm[d];
			for (int j = 0; j < v.size(); ++j) {
				if (v[j].first == x[i] && v[j].second == y[i]) {
					swap(v[j], v.back());
					break;
				}
			}
			add(x[i], y[i], -1);
			for (int j = 0; j + 1 < v.size(); ++j)
				add(v[j].first + x[i], v[j].second + y[i], -2);
			v.pop_back();
		}
		else {
			int ans = cur;
			int xx = lower_bound(vv.begin(), vv.end(), make_pair(x[i], y[i])) - vv.begin();
			ans -= cc[xx];
			cout << ans << "\n";
		}
	}
	return 0;
}