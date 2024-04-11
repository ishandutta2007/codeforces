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
ll h, w;

ll get(ll x, ll y) {
	if (y == 0) {
		return x;
	}
	if (x == h) {
		return h + y;
	}
	if (y == w) {
		return h + w + (h - x);
	}
	return h + w + h + (w - y);
}

vector<pair<ll, ll> > get(ll h, ll w, ll x, ll a, ll b) {
	if (a <= 0 && b <= 0)
		return {};
	if (a >= w && b >= w)
		return {};
	if (x >= h || x <= 0)
		return {};
	if (a > 0 && a < w && b > 0 && b < w)
		return {};
	int fl = 0;
	if (a > b)
		swap(a, b), fl = 1;
	vector<pair<ll, ll> > ans;
	if (a <= 0 && b >= w) {
		ans.push_back(make_pair(x, 0));
		ans.push_back(make_pair(x, w));
	}
	else if (a > 0) {
		ans.push_back(make_pair(x, w));
	}
	else {
		ans.push_back(make_pair(x, 0));
	}
	if (fl)
		reverse(ans.begin(), ans.end());
	return ans;
}
const int MAXN = 120000;

ll x[MAXN];
vector<int> eds[MAXN];
int was[MAXN];
ll y[MAXN];

void add_edge(int a, int b) {
	eds[a].push_back(b);
	eds[b].push_back(a);
}

void dfs1(int v) {
	was[v] = 1;
	for (int u: eds[v]) {
		if (!was[u])
			dfs1(u);
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1 *= 2, y1 *= 2, x2 *= 2, y2 *= 2;
	swap(y1, y2);
	h = x2 - x1;
	w = y2 - y1;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		x[i] *= 2, y[i] *= 2;
		x[i] -= x1;
		y[i] -= y1;
	}
	int fl = 0;
	for (int i = 0; i < n; ++i) {
		if (x[i] < 0 || y[i] < 0 || x[i] > h || y[i] > w) {
			rotate(x, x + i, x + n);
			rotate(y, y + i, y + n);
			fl = 1;
			break;
		}
	}
	if (!fl) {
		cout << 1 << "\n";
		return 0;
	}
	x[n] = x[0];
	y[n] = y[0];
	int cnt = 0;
	vector<pair<ll, int> > vv;
	for (int i = 0; i < n; ++i) {
		if (x[i] == x[i + 1]) {
			auto tmp = get(h, w, x[i], y[i], y[i + 1]);
			for (auto x: tmp)
				vv.push_back(make_pair(get(x.first, x.second), cnt++));
		}
		else {
			auto tmp = get(w, h, y[i], x[i], x[i + 1]);
			for (auto x: tmp)
				vv.push_back(make_pair(get(x.second, x.first), cnt++));
		}
	}
	if (vv.empty()) {
		ll a = h / 2, b = w / 2;
		ld ang = 0;
		for (int i = 0; i < n; ++i)
			ang += atan2((x[i] - a) * (y[i + 1] - b) - (y[i] - b) * (x[i + 1] - a), (x[i] - a) * (x[i + 1] - a) + (y[i] - a) * (y[i + 1] - a));
		if (abs(ang) <= 1)
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
		return 0;
	}
	assert(vv.size() % 2 == 0);
	for (int i = 0; i < vv.size(); i += 2) {
		add_edge(vv[i].second, vv[i + 1].second);
	}
	sort(vv.begin(), vv.end());
	for (int i = 0; i < vv.size(); ++i) {
		if (vv[i].second == 0) {
			rotate(vv.begin(), vv.begin() + i, vv.end());
			break;
		}
	}
	rotate(vv.begin(), vv.begin() + 1, vv.end());
	for (int i = 0; i < vv.size(); i += 2) {
		add_edge(vv[i].second, vv[i + 1].second);
	}
	int ans = 0;
	for (int i = 0; i < cnt; ++i) {
		if (!was[i])
			dfs1(i), ++ans;
	}
	cout << ans << "\n";
	return 0;
}