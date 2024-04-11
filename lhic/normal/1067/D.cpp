#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)


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

const int MAXN = 120000;

int n;
ll t;

ld p[MAXN];
ll a[MAXN];
vector<pair<ld, ld> > vv;
ld br[MAXN];

ld eps1 = 1e-12;

bool bad(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c) {
	return (b.second - a.second) / (a.first - b.first) >= (c.second - b.second) / (b.first - c.first);
}

int main() {
	cout.setf(ios::fixed);
	cout.precision(20);
	scanf("%d%lld", &n, &t);
	ld b = 0;
	for (int i = 0; i < n; ++i) {
		ll B;
		scanf("%lld%lld%Lf", a + i, &B, p + i);
		b = max(b, B * p[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (p[i] != 0) {
			vv.emplace_back(1 - p[i], b - p[i] * a[i]);
		}
	}
	if (vv.size() == 0) {
		cout << 0 << "\n";
		return 0;
	}
	sort(ALL(vv));
	reverse(ALL(vv));
	vector<pair<ld, ld>> st;
	for (auto p: vv) {
		if (!st.empty() && abs(st.back().first - p.first) <= eps1) {
			if (st.back().second < p.second)
				continue;
			st.pop_back();
		}
		while (st.size() >= 2 && bad(st[st.size() - 2], st[st.size() - 1], p))
			st.pop_back();
		st.push_back(p);
	}
	ld k = 0;
	int now = 0;
	for (int i = 0; i + 1 < st.size(); ++i)
		br[i] = (st[i + 1].second - st[i].second) / (st[i].first - st[i + 1].first);
	ll tmpt = t;
	while (t) {
		while (now + 1 < st.size() && br[now] <= k)
			++now;
		vector<pair<ld, ld>> go;
		go.push_back(st[now]);
		for (int i = 0; i < 40; ++i)
			go.emplace_back(go.back().first * go.back().first, go.back().second * (1 + go.back().first));
		for (int i = go.size() - 1; i >= 0; --i) {
			if ((1ll << i) <= t && (now + 1 == st.size() || go[i].first * k + go[i].second <= br[now])) {
				t -= (1ll << i);
				k = go[i].first * k + go[i].second;
			}
		}
		if (t) {
			k = go[0].first * k + go[0].second;
			--t;
		}
	}
	cout << tmpt * b - k << "\n";
	return 0;
}