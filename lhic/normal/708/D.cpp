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


typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e9;
const int MAXN = 200;

struct edge {
	int a, b;
	ll w, f, c;
};
int n, m;

int ff[MAXN];
vector<edge> ed;
vector<int> eds[MAXN];
ll dd[MAXN];
ll en[MAXN];
ll gg[MAXN];
int s, t;


void make_edge(int a, int b, ll c, ll w) {
	edge x;
	x.a = a, x.b = b, x.c = c, x.w = w, x.f = 0;
	eds[a].push_back(ed.size());
	ed.push_back(x);
	swap(x.a, x.b);
	x.c = 0;
	x.w = -x.w;
	eds[b].push_back(ed.size());
	ed.push_back(x);
}


ll flow(int k) {
	ll nowc = 0;
	while (k > 0) {
		fill(dd, dd + t + 1, INF);
		fill(gg, gg + t + 1, -1);
		dd[s] = 0;
		fill(en, en + t + 1, 0);
		queue<int> qu;
		qu.push(s);
		en[s] = 1;
		while (!qu.empty()) {
			int x = qu.front();
			en[x] = 0;
			qu.pop();
			for (int e: eds[x]) {
				int u = ed[e].b;
				ll w = ed[e].w;
				ll fr = ed[e].c - ed[e].f;
				if (fr == 0)
					continue;
				if (dd[u] > dd[x] + w) {
					dd[u] = dd[x] + w;
					gg[u] = e;
					if (!en[u])
						qu.push(u), en[u] = 1;
				}
			}
		}
		int now = t;
		ll mn = k;
		while (now != s) {
			int e = gg[now];
			mn = min(mn, ed[e].c - ed[e].f);
			now = ed[e].a;
		}
		nowc += dd[t] * mn;
		now = t;
		while (now != s) {
			int e = gg[now];
			ed[e].f += mn;
			ed[e ^ 1].f -= mn;
			now = ed[e].a;
		}
		k -= mn;
	}
	return nowc;
}




int main() {
	cin >> n >> m;
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		int u, v, c, f;
		cin >> u >> v >> c >> f;
		--u;
		--v;
		ff[u] -= f;
		ff[v] += f;
		if (f <= c) {
			make_edge(u, v, c - f, 1);
			make_edge(u, v, INF, 2);
			make_edge(v, u, f, 1);
		}
		else {
			ans += f - c;
			make_edge(u, v, INF, 2);
			make_edge(v, u, f - c, 0);
			make_edge(v, u, c, 1);
		}
	}
	ll go = 0;
	s = n;
	t = n + 1;
	for (int i = 1; i < n - 1; ++i) {
		go += abs(ff[i]);
		if (ff[i] < 0)
			make_edge(i, t, -ff[i], -INF);
		else
			make_edge(s, i, ff[i], -INF);
	}
	make_edge(s, 0, INF, 0);
	make_edge(s, n - 1, INF, 0);
	make_edge(0, t, INF, 0);
	make_edge(n - 1, t, INF, 0);

	cout << ans + go * INF + flow(go) << "\n";

	return 0;
}