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

const int MAXN = 12000;

struct edge {
	int a, b, c, f;
};

void ex0() {
	cout << "unfair\n";
	exit(0);
}
int n, b, q;
int go[MAXN];
int cc[MAXN];
int gg[6];
int was[MAXN * 2];
int s, t;

vector<edge> ed;

vector<int> eds[MAXN * 2];

void make_edge(int a, int b, int c) {
	edge x;
	x.a = a;
	x.b = b;
	x.c = c;
	x.f = 0;
	eds[a].push_back(ed.size());
	ed.push_back(x);
	eds[b].push_back(ed.size());
	swap(x.a, x.b);
	x.c = 0;
	ed.push_back(x);
}

int dfs(int v, int fl) {
	if (v == t)
		return fl;
	was[v] = 1;
	for (int u: eds[v]) {
		int x = ed[u].b;
		int fr = ed[u].c - ed[u].f;
		if (fr != 0 && !was[x]) {
			int go = min(fl, fr);
			go = dfs(x, go);
			if (go > 0) {
				ed[u].f += go;
				ed[u ^ 1].f -= go;
				return go;
			}
		}
	}
	return 0;
}


int main() {
	scanf("%d%d%d", &n, &b, &q);
	for (int i = 0; i <= b; ++i)
		go[i] = -1;
	go[0] = 0;
	go[b] = n;
	for (int i = 0; i < q; ++i) {
		int r, c;
		scanf("%d%d", &r, &c);
		if (go[r] != -1 && go[r] != c)
			ex0();
		go[r] = c;
	}
	int lst = 0;
	int nw = b;
	make_edge(nw, 0, 1);
	for (int i = 1; i <= b; ++i) {
		if (go[i] == -1) {
			make_edge(nw, i, 1);
			continue;
		}
		cc[nw] = go[i] - go[lst];
		if (cc[nw] < 0)
			ex0();
		++nw;
		lst = i;
		if (i != b)
			make_edge(nw, i, 1);
	}
	s = nw;
	t = s + 1;
	for (int i = 0; i < 5; ++i)
		gg[i] = t + 1 + i;
	for (int i = b; i < nw; ++i)
		make_edge(s, i, cc[i]);
	for (int i = 0; i < b; ++i)
		make_edge(i, gg[i % 5], 1);
	for (int i = 0; i < 5; ++i)
		make_edge(gg[i], t, n / 5);
	int flow = 0;
	while (true) {
		memset(was, 0, sizeof(was));
		int x = dfs(s, 100000);
		if (x == 0)
			break;
		flow += x;
	}
	if (flow == n) {
		cout << "fair\n";
	}
	else
		ex0();
	return 0;
}