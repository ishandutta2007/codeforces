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


const int MAXN = 700;
const int INF = 1000000000;

int n, m;
int s, t;

int a[MAXN];
int cl[MAXN];
int go[MAXN];

struct edge {
	int a, b, c, f, w;
};

vector<edge> ed;

vector<int> eds[MAXN];
int lst[30];
int ph[MAXN];
int dd[MAXN];


void addEdge(int a, int b, int c, int w) {
	edge x;
	x.a = a;
	x.b = b;
	x.c = c;
	x.f = 0;
	x.w = w;
	eds[a].push_back(ed.size());
	ed.push_back(x);
	swap(x.a, x.b);
	x.c = 0;
	x.w = -x.w;
	eds[b].push_back(ed.size());
	ed.push_back(x);
}

void flow(int k) {
	for (int i = 0; i <= t; ++i)
		ph[i] = INF;
	ph[s] = 0;
	for (auto u: eds[s]) {
		if (ed[u].c > ed[u].c)
			ph[ed[u].b] = min(ph[ed[u].b], ph[s] + ed[u].w);
	}
	for (int i = 0; i < 2 * n; ++i) {
		for (auto u: eds[i])
			if (ed[u].c > ed[u].c)
				ph[ed[u].b] = min(ph[ed[u].b], ph[i] + ed[u].w);
	}
	for (int it = 0; it < k; ++it) {
		set<pair<int, int> > ss;
		fill(dd, dd + t + 1, INF);
		dd[s] = 0;
		go[s] = -1;
		ss.insert(make_pair(dd[s], s));
		while (!ss.empty()) {
			int x = ss.begin()->second;
			ss.erase(ss.begin());
			for (auto u: eds[x]) {
				int b = ed[u].b;
				int w = ed[u].w - ph[b] + ph[x];
				if (ed[u].c == ed[u].f)
					continue;
				if (dd[b] > dd[x] + w) {
					ss.erase(make_pair(dd[b], b));
					dd[b] = dd[x] + w;
					go[b] = u;
					ss.insert(make_pair(dd[b], b));
				}
			}
		}
		for (int i = 0; i <= t; ++i)
			ph[i] += dd[i];
		if (ph[t] > 0)
			break;
		int now = t;
		while (now != s) {
			int u = go[now];
			ed[u].f += 1;
			ed[u ^ 1].f -= 1;
			now = ed[u].a;
		}
	}
}

int dfs(int v, int c) {
	if (v / 2 < n)
		cl[v / 2] = c;
	if (v == t)
		return 1;
	for (auto u: eds[v]) {
		if (ed[u].f > 0) {
			ed[u].f -= 1;
			ed[u ^ 1].f += 1;
			return dfs(ed[u].b, c);
		}
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	s = 2 * n;
	t = s + 1;
	for (int i = 0; i < n; ++i) {
		addEdge(2 * i, 2 * i + 1, 1, -1000000);
		addEdge(s, 2 * i, 1, __builtin_popcount(a[i]));
		addEdge(2 * i + 1, t, 1, 0);
	}
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			if (a[i] == a[j])
				addEdge(2 * i + 1, 2 * j, 1, 0);
			else
				addEdge(2 * i + 1, 2 * j, 1, __builtin_popcount(a[j]));
		}
	flow(m);
	for (int i = 0; i < m; ++i)
		if (!dfs(s, i))
			break;
	int cs = 0;
	vector<string> vv;
	for (int i = 0; i < n; ++i) {
		int x = cl[i];
		if (a[i] != lst[x]) {
			cs += __builtin_popcount(a[i]);
			lst[x] = a[i];
			string s = string(1, 'a' + x) + "=" + to_string(a[i]);
			vv.push_back(s);
		}
		string s = "print(" + string(1, 'a' + x) + ")";
		vv.push_back(s);
	}
	cout << vv.size() << " " << cs << "\n";
	for (auto i: vv)
		cout << i << "\n";
	return 0;
}