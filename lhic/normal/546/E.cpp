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

const int MAXN = 1000;
const int INF = 1e8;


struct edge {
	int a, f, c;
};

vector<int> eds[MAXN];
vector<edge> ed;
int dd[MAXN];
int pnt[MAXN];
int d[MAXN][MAXN];
int a[MAXN];
int b[MAXN];

int n, m;
int s, t;

void make_edge(int a, int b, int c) {
	edge x;
	x.a = a ^ b;
	x.f = 0;
	x.c = c;
	ed.push_back(x);
	x.c = 0;
	ed.push_back(x);
	eds[a].push_back(ed.size() - 2);
	eds[b].push_back(ed.size() - 1);
}


int dfs(int v, int fl, int mb) {
	if (v == t)
		return fl;
	int sum = 0;
	while (fl >= mb && pnt[v] < (int)eds[v].size()) {
		int x = eds[v][pnt[v]];
		int fr = ed[x].c - ed[x].f;
		int u = ed[x].a ^ v;
		if (fr < mb || pnt[u] == (int)eds[u].size() || dd[u] != dd[v] + 1) {
			++pnt[v];
			continue;
		}
		fr = dfs(u, min(fl, fr), mb);
		ed[x].f += fr;
		ed[x ^ 1].f -= fr;
		fl -= fr;
		assert(fl >= 0);
		sum += fr;
		if (fl != 0)
			++pnt[v];
	}
	return sum;
}

int dinic(int mb) {
	int sum = 0;
	int lst = 0;
	do {
		lst = 0;
		fill(dd, dd + 2 * n + 2, INF);
		dd[s] = 0;
		queue<int> qu;
		qu.push(s);
		while (!qu.empty()) {
			int x = qu.front();
			qu.pop();
			for (int i = 0; i < (int)eds[x].size(); ++i) {
				if (ed[eds[x][i]].f + mb <= ed[eds[x][i]].c) {
					int u = ed[eds[x][i]].a ^ x;
					if (dd[u] > dd[x] + 1)
						dd[u] = dd[x] + 1, qu.push(u);
				}
			}
		}
		if (dd[t] == INF)
			continue;
		memset(pnt, 0, sizeof(pnt[0]) * (2 * n + 2));
		lst = dfs(s, INF, mb);
		sum += lst;
	} while (lst);
	return sum;
}


int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	scanf("%d%d", &n, &m);
	int sum = 0, sum2 = 0;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), sum += a[i];
	for (int i = 0; i < n; ++i)
		scanf("%d", b + i), sum2 += b[i];
	if (sum != sum2) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		make_edge(a, b + n, INF);
		make_edge(b, a + n, INF);
	}
	s = 2 * n;
	t = s + 1;
	for (int i = 0; i < n; ++i) {
		make_edge(s, i, a[i]);
		make_edge(i, i + n, INF);
		make_edge(i + n, t, b[i]);
	}
	int flow = 0;
	for (int i = 7; i >= 0; --i)
		flow += dinic(1 << i);
	if (flow != sum) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)eds[i].size(); ++j) {
			int u = (ed[eds[i][j]].a ^ i) - n;
			d[i][u] += ed[eds[i][j]].f;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << d[i][j] << " ";
		cout << "\n";
	}

	return 0;
}