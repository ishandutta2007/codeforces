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

struct edge {
	int a, b, c, f;
};
const int INF = 1e9;

vector<int> eds[10100];
vector<edge> ed;
int dd[10100];
int s, t;
int pp[10100];
queue<int> qu;
vector<pair<int, int> > edd;
int n, m;

void add_edge(int a, int b, int c) {
	edge x;
	x.a = a, x.b = b, x.c = c, x.f = 0;
	eds[a].push_back(ed.size());
	ed.push_back(x);
	swap(x.a, x.b);
	x.c = 0;
	eds[b].push_back(ed.size());
	ed.push_back(x);
}

int dfs1(int v, int fl) {
	if (v == t)
		return fl;
	if (dd[v] >= dd[t])
		return 0;
	int now = 0;
	for (; pp[v] < eds[v].size(); ++pp[v]) {
		int e = eds[v][pp[v]];
		int u = ed[e].b;
		if (ed[e].c == ed[e].f || dd[u] != dd[v] + 1)
			continue;
		int go = min(fl, ed[e].c - ed[e].f);
		go = dfs1(u, go);
		ed[e].f += go;
		ed[e ^ 1].f -= go;
		now += go;
		fl -= go;
		if (fl == 0)
			break;
	}
	return now;
}

int dinic() {
	fill(dd, dd + t + 1, INF);
	qu.push(s);
	dd[s] = 0;
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int e: eds[x]) {
			int u = ed[e].b;
			if (dd[u] > dd[x] + 1 && ed[e].c != ed[e].f) {
				dd[u] = dd[x] + 1;
				qu.push(u);
			}
		}
	}
	if (dd[t] == INF)
		return 0;
	fill(pp, pp + t + 1, 0);
	return dfs1(s, INF);
}

int flow() {
	int ans = 0;
	while (true) {
		int x = dinic();
		if (!x)
			break;
		ans += x;
	}
	return ans;
}

int check(int d) {
	ed.clear();
	for (int i = 0; i <= t; ++i)
		eds[i].clear();
	for (int i = 0; i < n; ++i) {
		add_edge(s, i, d);
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		tie(x, y) = edd[i];
		add_edge(x, n + i, 1);
		add_edge(y, n + i, 1);
		add_edge(n + i, t, 1);
	}
	if (flow() != m)
		return 0;
	else
		return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	s = n + m;
	t = s + 1;
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		edd.push_back(make_pair(x, y));
	}
	int l = -1;
	int r = n + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << "\n";
	check(r);
	for (int i = 0; i < n; ++i) {
		for (int j: eds[i]) {
			int b = ed[j].b;
			if (b < s && b >= n && ed[j].f) {
				b -= n;
				int y = (edd[b].first ^ edd[b].second ^ i);
				cout << i + 1 << " " << y + 1 << "\n";
			}
		}
	}
	return 0;
}