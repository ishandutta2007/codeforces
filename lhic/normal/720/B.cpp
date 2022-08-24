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
const int MAXN = 120000;
const int INF = 1e9;
int s, t;

struct edge {
	int a, b, c, f;
};

vector<int> eds[MAXN];
vector<edge> ed;
int cl[MAXN];
vector<int> go[MAXN];
int cc;
int fr[MAXN];
int was[MAXN];
int dd[MAXN];
int pp[MAXN];
vector<pair<int, int> > st;
int n, m;

void make_edge(int a, int b, int c) {
	edge x;
	x.a = a, x.b = b, x.c = c, x.f = 0;
	eds[a].push_back(ed.size());
	ed.push_back(x);
	swap(x.a, x.b);
	x.c = 0;
	eds[b].push_back(ed.size());
	ed.push_back(x);
}

void dfs1(int v, int fr) {
	was[v] = 1;
	for (int e: eds[v]) {
		int u = (ed[e].a ^ ed[e].b) ^ v;
		if (!was[u]) {
			st.push_back(make_pair(v, e));
			dfs1(u, v);
			st.pop_back();
		}
		else if (u != fr && was[u] == 1) {
			st.push_back(make_pair(v, e));
			for (int i = (int)st.size() - 1; i >= 0; --i) {
				int ee = st[i].second;
				go[cc].push_back(ed[ee].c);
				cl[ee] = 1;
				if (st[i].first == u)
					break;
			}
			++cc;
			st.pop_back();
		}
	}
	was[v] = 2;
}

int dfs2(int v, int fl) {
	if (v == t)
		return fl;
	if (dd[v] >= dd[t])
		return 0;
	int now = 0;
	for (; pp[v] < (int)eds[v].size(); ++pp[v]) {
		int e = eds[v][pp[v]];
		int u = ed[e].b;
		int go = ed[e].c - ed[e].f;
		if (go == 0 || dd[u] != dd[v] + 1)
			continue;
		go = dfs2(u, min(go, fl));
		fl -= go;
		ed[e].f += go;
		ed[e ^ 1].f -= go;
		now += go;
		if (fl == 0)
			break;
	}
	return now;
}

int dinic() {
	fill(dd, dd + t + 1, INF);
	queue<int> qu;
	dd[s] = 0;
	qu.push(s);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int e: eds[x]) {
			int u = ed[e].b;
			int f = ed[e].c - ed[e].f;
			if (f != 0 && dd[u] > dd[x] + 1) {
				dd[u] = dd[x] + 1;
				qu.push(u);
			}
		}
	}
	if (dd[t] >= INF)
		return 0;
	fill(pp, pp + t + 1, 0);
	return dfs2(s, INF);
}

int flow() {
	int ans = 0;
	while (true) {
		int x = dinic();
		if (x == 0)
			break;
		ans += x;
	}
	return ans;
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b, --c;
		eds[a].push_back(ed.size());
		eds[b].push_back(ed.size());
		edge x;
		x.a = a;
		x.b = b;
		x.c = c;
		ed.push_back(x);
	}
	dfs1(0, -1);
	for (int i = 0; i < m; ++i)
		if (!cl[i]) {
			int c = ed[i].c;
			fr[c] = 1;
		}
	int ans = 0;
	for (int i = 0; i < m; ++i)
		if (fr[i])
			++ans;
	for (int i = 0; i < n; ++i)
		eds[i].clear();
	ed.clear();
	s = m + cc;
	t = s + 1;
	for (int i = 0; i < cc; ++i) {
		for (int j: go[i])
			make_edge(j, i + m, 1);
		make_edge(i + m, t, go[i].size() - 1);
	}
	for (int i = 0; i < m; ++i)
		if (!fr[i])
			make_edge(s, i, 1);
	ans += flow();
	cout << ans << "\n";
	return 0;
}