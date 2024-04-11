#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 210000;
const int LOG = 20;

const ll INF = 1e18;
int n, m, s;
ll dd[MAXN];
vector<pair<int, ll> > eee[MAXN];
vector<tuple<int, int, ll> > ed;
set<pair<ll, int> > ss;
vector<pair<ll, int> > vv;
int go[MAXN];
vector<int> reds[MAXN];
vector<int> eds[MAXN];
int dp[MAXN];
int up[LOG][MAXN];
int h[MAXN];

int lca(int a, int b) {
	if (h[a] < h[b])
		swap(a, b);
	int d = h[a] - h[b];
	for (int i = LOG - 1; i >= 0; --i) {
		if ((1 << i) <= d)
			a = up[i][a], d -= (1 << i);
	}
	if (a == b)
		return a;
	for (int i = LOG - 1; i >= 0; --i) {
		if (up[i][a] != up[i][b])
			a = up[i][a], b = up[i][b];
	}
	return up[0][a];
}

void dfs1(int v) {
	dp[v] = 1;
	for (int u: eds[v]) {
		dfs1(u);
		dp[v] += dp[u];
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	--s;
	for (int i = 0; i < m; ++i) {
		int a, b;
		ll w;
		scanf("%d%d%lld", &a, &b, &w);
		--a, --b;
		eee[a].push_back(make_pair(b, w));
		eee[b].push_back(make_pair(a, w));
		ed.push_back(make_tuple(a, b, w));
	}
	for (int i = 0; i < n; ++i)
		dd[i] = INF;
	dd[s] = 0;
	for (int i = 0; i < n; ++i)
		ss.insert(make_pair(dd[i], i));
	while (!ss.empty()) {
		int x = ss.begin()->second;
		ss.erase(ss.begin());
		for (auto e: eee[x]) {
			int u = e.first;
			if (dd[u] > dd[x] + e.second) {
				ss.erase(make_pair(dd[u], u));
				dd[u] = dd[x] + e.second;
				ss.insert(make_pair(dd[u], u));
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (dd[i] < INF)
			vv.push_back(make_pair(dd[i], i));
	}
	sort(vv.begin(), vv.end());
	n = vv.size();
	for (int i = 0; i < n; ++i)
		go[vv[i].second] = i;
	for (int i = 0; i < m; ++i) {
		int a, b;
		ll w;
		tie(a, b, w) = ed[i];
		if (dd[a] + w == dd[b]) {
			reds[go[b]].push_back(go[a]);
		}
		if (dd[b] + w == dd[a]) {
			reds[go[a]].push_back(go[b]);
		}
	}
	for (int i = 1; i < n; ++i) {
		int lc = reds[i][0];
		for (int u: reds[i])
			lc = lca(lc, u);
		eds[lc].push_back(i);
		up[0][i] = lc;
		for (int j = 1; j < LOG; ++j)
			up[j][i] = up[j - 1][up[j - 1][i]];
		h[i] = h[lc] + 1;
	}
	dfs1(0);
	int ans = 0;
	for (int i = 1; i < n; ++i)
		ans = max(ans, dp[i]);
	cout << ans << "\n";
	return 0;
}