#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const ll INF = 2e9;

const int N = 1100;
ll cur, ad;

int n, m;
vector<pair<int, int>> eds[N];
vector<array<ll, 3>> ed;
ll a[N];
ll b[N];
int was[N];

pair<ll, int> go[N][2];

void solve() {
	cur = 0;
	ad = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		eds[i].clear();
		was[i] = 0;
	}
	ed.clear();
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		eds[x].emplace_back(y, ed.size());
		ed.push_back({x, y, INF});
		eds[y].emplace_back(x, ed.size());
		ed.push_back({y, x, INF});
	}
	for (int i = 0; i < ed.size(); ++i) {
		if (ed[i][1] == 0) {
			ed[i][2] = 0;
		}
	}

	for (int it = 0; it <= 2 * n + 1; ++it) {
		for (int i = 0; i < n; ++i) {
			go[i][0] = go[i][1] = {INF, -1};
		}
		for (int i = 0; i < ed.size(); ++i) {
			int u = ed[i][0];
			int v = ed[i][1];
			ll d = ed[i][2];
			if (d < go[u][1].first) {
				go[u][1] = {d, v};
				if (go[u][1].first < go[u][0].first) {
					swap(go[u][1], go[u][0]);
				}
			}
		}
		for (int i = 0; i < ed.size(); ++i) {
			int u = ed[i][0];
			int v = ed[i][1];
			ll d = ed[i][2];
			ll gg = go[v][1].first;
			if (go[v][0].second != u) {
				gg = go[v][0].first;
			}
			ed[i][2] = min(d, max(a[v], gg - b[v]));
		}
	}

	set<pair<ll, int>> ss;

	auto add = [&] (int u) {
		was[u] = 1;
		cur += b[u];
		for (auto [v, e] : eds[u]) {
			if (!was[v]) {
				ss.emplace(ed[e][2], e);
			}
		}
	};

	add(0);

	while (!ss.empty()) {
		auto tmp = *ss.begin();
		ss.erase(ss.begin());
		int e = tmp.second;
		int v = ed[e][1];
		if (was[v]) {
			continue;
		}
		if (cur < tmp.first) {
			ad += tmp.first - cur;
			cur = tmp.first;
		}
		add(v);
	}
	cout << ad + 1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		solve();
	}
	return 0;
}