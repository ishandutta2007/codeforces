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

const int MAXN = 500;
const int INF = 1e9;

struct edge {
	int a, b, f, c;
};

int was[MAXN];
vector<int> eds[MAXN];
vector<edge> ed;
vector<int> eee[MAXN];
int cs[MAXN];
int q[MAXN];
int p[MAXN];
int pp[MAXN];
int dd[MAXN];
int S, T;
int n;

int dfsc(int v) {
	was[v] = 1;
	for (int u: eee[v]) {
		if (q[u] == -1) {
			q[u] = v, p[v] = u;
			return 1;
		}
	}
	for (int u: eee[v]) {
		if (!was[q[u]]) {
			if (dfsc(q[u])) {
				p[v] = u, q[u] = v;
				return 1;
			}
		}
	}
	return 0;
}


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

int dfsf(int v, int fl, int mn) {
	if (v == T)
		return fl;
	if (dd[v] >= dd[T])
		return 0;
	int sum = 0;
	for (; fl >= mn && pp[v] < (int)eds[v].size(); ++pp[v]) {
		int e = eds[v][pp[v]];
		int u = ed[e].b;
		if (dd[u] != dd[v] + 1)
			continue;
		int go = ed[e].c - ed[e].f;
		if (go < mn)
			continue;
		go = dfsf(u, min(fl, go), mn);
		fl -= go;
		ed[e].f += go;
		ed[e ^ 1].f -= go;
		sum += go;
		if (fl == 0)
			break;
	}
	return sum;
}

int dinic(int mn) {
	fill(dd, dd + T + 1, INF);
	dd[S] = 0;
	queue<int> qu;
	qu.push(S);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int e: eds[x]) {
			int u = ed[e].b;
			if (ed[e].f + mn <= ed[e].c) {
				if (dd[u] > dd[x] + 1)
					dd[u] = dd[x] + 1, qu.push(u);
			}
		}
	}
	if (dd[T] >= INF)
		return 0;
	fill(pp, pp + T + 1, 0);
	return dfsf(S, INF, mn);
}

int flow() {
	int sum = 0;
	for (int now = 1 << 20; now > 0; now /= 2) {
		while (true) {
			int x = dinic(now);
			if (!x)
				break;
			sum += x;
		}
	}
	return sum;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int a;
			scanf("%d", &a);
			--a;
			eee[i].push_back(a);
		}
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", cs + i);
	int now = 0;
	fill(p, p + n, -1);
	fill(q, q + n, -1);
	while (now < n) {
		memset(was, 0, sizeof(was));
		for (int i = 0; i < n; ++i)
			if (!was[i] && p[i] == -1)
				if (dfsc(i))
					++now;
	}
	S = n;
	T = S + 1;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (cs[i] >= 0)
			make_edge(i, T, cs[i]);
		else
			sum += cs[i], make_edge(S, i, -cs[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j: eee[i]) {
			if (q[j] != i)
				make_edge(i, q[j], INF);
		}
	}

	cout << flow() + sum << "\n";

	return 0;
}