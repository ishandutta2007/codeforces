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
const int MAXN = 210000;

int n, m, k;

set<pair<int, int>> ss;
int cc[MAXN];
vector<pair<int, int>> ed;
int dis[MAXN];
vector<pair<int, int>> eds[MAXN];
int ans[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		++cc[a], ++cc[b];
		ed.emplace_back(a, b);
		eds[a].emplace_back(b, i);
		eds[b].emplace_back(a, i);
	}
	for (int i = 0; i < n; ++i)
		ss.emplace(cc[i], i);
	for (int i = m - 1; i >= 0; --i) {
		while (!ss.empty() && ss.begin()->first < k) {
			int x = ss.begin()->second;
			ss.erase(ss.begin());
			dis[x] = 1;
			for (auto e: eds[x]) {
				int u = e.first;
				if (e.second > i)
					continue;
				if (!dis[u]) {
					ss.erase({cc[u], u});
					--cc[u];
					ss.insert({cc[u], u});
				}
			}
		}
		ans[i] = ss.size();
		int a, b;
		tie(a, b) = ed[i];
		if (!dis[a] && !dis[b]) {
			ss.erase({cc[a], a});
			ss.erase({cc[b], b});
			--cc[a], --cc[b];
			ss.insert({cc[a], a});
			ss.insert({cc[b], b});
		}
	}
	for (int i = 0; i < m; ++i)
		cout << ans[i] << "\n";
	return 0;
}