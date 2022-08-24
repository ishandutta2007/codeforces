#pragma GCC optimize "-O3"
#include <bits/stdc++.h>

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
const int SQ = 400;
const int MAXN = 120000;
const int MX = 100001;

vector<pair<ll, int> > gg[MAXN][2][2];
vector<ll> smm[MAXN][2];
ll sm[MAXN];
ll br[MAXN][2];
ll ad[MAXN][2];
int n;
const ll INF = 1e9 + 100;

void rb(int bl, int tp) {
	smm[bl][tp].resize(gg[bl][tp][1].size() + 1);
	smm[bl][tp][0] = 0;
	for (int i = 0; i < gg[bl][tp][1].size(); ++i)
		smm[bl][tp][i + 1] = smm[bl][tp][i] + gg[bl][tp][1][i].first;
}

void upd(int bl, int l, int r, ll k) {
	int tp = 0;
	if (k < 0)
		k = -k, tp = 1;
	int fl = 0;
	int now = 0;
	for (int i = 0; i < gg[bl][1 - tp][0].size(); ++i) {
		auto x = gg[bl][1 - tp][0][i];
		if (x.second < l || x.second >= r) {
			gg[bl][1 - tp][0][now] = x;
			++now;
			continue;
		}
		if (x.first == 0 && br[bl][1 - tp] != INF)
			x.first = br[bl][1 - tp];
		gg[bl][1 - tp][1].push_back(x);
		fl = 1;
		sm[bl] += x.first;
		if (x.first >= br[bl][1 - tp])
			ad[bl][1 - tp] += x.first - br[bl][1 - tp];
	}
	gg[bl][1 - tp][0].resize(now);
	if (fl) {
		sort(gg[bl][1 - tp][1].begin(), gg[bl][1 - tp][1].end());
		rb(bl, 1 - tp);
	}
	for (auto &x: gg[bl][tp][1]) {
		if (x.second < l || x.second >= r)
			continue;
		sm[bl] -= x.first;
		if (x.first >= br[bl][tp])
			ad[bl][tp] -= x.first - br[bl][tp];
		if (x.first == 0)
			x.first = k;
		else
			x.first = min(x.first, k);
		sm[bl] += x.first;
		if (x.first >= br[bl][tp])
			ad[bl][tp] += x.first - br[bl][tp];
	}
	sort(gg[bl][tp][1].begin(), gg[bl][tp][1].end());
	rb(bl, tp);
	for (auto &x: gg[bl][tp][0]) {
		if (x.second < l || x.second >= r)
			continue;
		if (x.first == 0)
			x.first = k;
		else
			x.first = min(x.first, k);
	}
}

void fupd(int bl, int k) {
	int tp = 0;
	if (k < 0)
		k = -k, tp = 1;
	if (br[bl][tp] <= k)
		return;
	int fl = 0;
	for (int i = 0; i < gg[bl][1 - tp][0].size(); ++i) {
		auto x = gg[bl][1 - tp][0][i];
		if (x.first == 0 && br[bl][1 - tp] != INF)
			x.first = br[bl][1 - tp];
		gg[bl][1 - tp][1].push_back(x);
		fl = 1;
		sm[bl] += x.first;
		if (x.first >= br[bl][1 - tp])
			ad[bl][1 - tp] += x.first - br[bl][1 - tp];
	}
	gg[bl][1 - tp][0].clear();
	if (fl) {
		sort(gg[bl][1 - tp][1].begin(), gg[bl][1 - tp][1].end());
		rb(bl, 1 - tp);
	}
	if (!gg[bl][tp][1].empty() && gg[bl][tp][1][0].first == 0) {
		int now = 0;
		while (now < gg[bl][tp][1].size() && gg[bl][tp][1][now].first == 0)
			gg[bl][tp][1][now].first = k, sm[bl] += k, ++now;
		sort(gg[bl][tp][1].begin(), gg[bl][tp][1].end());
		rb(bl, tp);
	}
	br[bl][tp] = k;
	int x = lower_bound(gg[bl][tp][1].begin(), gg[bl][tp][1].end(), make_pair((ll)k, 0)) - gg[bl][tp][1].begin();
	ad[bl][tp] = smm[bl][tp][gg[bl][tp][1].size()] - smm[bl][tp][x] - (ll)k * ((ll)gg[bl][tp][1].size() - x);
}

ll get(int bl, int l, int r) {
	ll ans = 0;
	for (auto x: gg[bl][0][1])
		if (x.second >= l && x.second < r)
			ans += min(x.first, br[bl][0]);
	for (auto x: gg[bl][1][1])
		if (x.second >= l && x.second < r)
			ans += min(x.first, br[bl][1]);
	return ans;
}

ll fget(int bl) {
	return sm[bl] - ad[bl][0] - ad[bl][1];
}


int main() {
	int q;
	scanf("%d", &q);
	int mx = 0;
	for (int i = 0; i < MX; ++i) {
		gg[i / SQ][0][0].push_back(make_pair(0, i));
		gg[i / SQ][1][0].push_back(make_pair(0, i));
		br[i / SQ][0] = br[i / SQ][1] = INF;
		mx = i / SQ;
	}
	for (int i = 0; i <= mx; ++i)
		rb(i, 0), rb(i, 1);
	while (q--) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if (t == 1) {
			int k;
			scanf("%d", &k);
			int lb = (l + SQ - 1) / SQ;
			int rb = r / SQ;
			if (l != lb * SQ) {
				upd(lb - 1, l, min(lb * SQ, r), k);
				l = lb * SQ;
			}
			if (l >= r)
				continue;
			if (r != rb * SQ) {
				upd(rb, rb * SQ, r, k);
				r = rb * SQ;
			}
			for (int i = lb; i < rb; ++i)
				fupd(i, k);
		}
		else {
			ll ans = 0;
			int lb = (l + SQ - 1) / SQ;
			int rb = r / SQ;
			if (l != lb * SQ) {
				ans += get(lb - 1, l, min(lb * SQ, r));
				l = lb * SQ;
			}
			if (l <= r && r != rb * SQ) {
				ans += get(rb, rb * SQ, r);
				r = rb * SQ;
			}
			for (int i = lb; i < rb; ++i)
				ans += fget(i);
			printf("%lld\n", ans);
		}
	}
	return 0;
}