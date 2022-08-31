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

const int MAXN = 2100;
const int INF = 1e9 + 1e7;

struct edge {
	int a, f, c, w;
};

int st[MAXN];
int l[MAXN];
int c[MAXN];

vector<edge> ed;
vector<int> eds[MAXN];

int dd[MAXN];
int dd2[MAXN];
int rmq[MAXN * 2];
int go[MAXN];
int ph[MAXN];
int n, k;
int s, t;


void make_edge(int a, int b, int c, int w) {
	edge x;
	x.a = a ^ b;
	x.c = c;
	x.w = w;
	x.f = 0;
	ed.push_back(x);
	x.c = 0;
	x.w = -w;
	ed.push_back(x);
	eds[a].push_back(ed.size() - 2);
	eds[b].push_back(ed.size() - 1);
}

int minn(int a, int b) {
	return (dd2[a] < dd2[b] ? a : b);
}

void upd(int v, int x) {
	dd2[v] = x;
	v += t;
	while (v) {
		v = (v - 1) >> 1;
		rmq[v] = minn(rmq[v * 2 + 1], rmq[v * 2 + 2]);
	}
}

void uu(int v) {
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int xx = eds[v][i];
		int u = ed[xx].a ^ v;
		if (ed[xx].c - ed[xx].f > 0 && dd[u] > dd[v] + ed[xx].w) {
			dd[u] = dd[v] + ed[xx].w;
		}
	}
}

void mincost() {
	queue<int> qu;
	fill(dd, dd + t + 1, INF);
	dd[s] = 0;
	uu(s);
	vector<pair<int, int> > vv;
	for (int i = 0; i < n; ++i)
		vv.push_back(make_pair(st[i], i));
	sort(vv.begin(), vv.end());
	for (int i = 0; i < (int)vv.size(); ++i) {
		uu(vv[i].second);
		uu(vv[i].second + n);
	}


	for (int it = 0; it < k; ++it) {
		for (int i = 0; i < t + 1; ++i)
			ph[i] = min(INF, ph[i] + dd[i]);
		fill(dd, dd + t + 1, INF);
		fill(dd2, dd2 + t + 1, INF);
		dd[s] = 0;
		dd2[s] = 0;
		for (int i = 0; i < t + 1; ++i)
			rmq[i + t] = i;
		for (int i = t - 1; i >= 0; --i)
			rmq[i] = minn(rmq[i * 2 + 1], rmq[i * 2 + 2]);
		while (true) {
			int x = rmq[0];
			if (dd[x] == INF)
				break;
			upd(x, INF);
			if (x == t)
				break;
			for (int i = 0; i < (int)eds[x].size(); ++i) {
				int g = eds[x][i];
				int u = ed[g].a ^ x;
				int w = ed[g].w + ph[x] - ph[u];
				if (ed[g].c == ed[g].f)
					continue;
				if (dd[u] > dd[x] + w) {
					dd[u] = dd[x] + w;
					go[u] = g;
					upd(u, dd[u]);
				}
			}
		}

		if (dd[t] == INF)
			return;
		int now = t;
		while (now != s) {
			ed[go[now]].f += 1;
			ed[go[now] ^ 1].f -= 1;
			now = ed[go[now]].a ^ now;
		}
	}





}



int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d%d%d", st + i, l + i, c + i);

	s = 2 * n;
	t = 2 * n + 1;

	for (int i = 0; i < n; ++i) {
		make_edge(i, i + n, 1, -c[i]);
		make_edge(s, i, 1, 0);
		make_edge(i + n, t, 1, 0);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (st[j] - st[i] >= l[i]) {
				make_edge(i + n, j, 1, 0);
			}
		}

	mincost();

	for (int i = 0; i < n; ++i) {
		int fl = 0;
		for (int j = 0; j < (int)eds[i].size(); ++j) {
			int u = ed[eds[i][j]].a ^ i;
			int f = ed[eds[i][j]].f;
			if (u == i + n && f)
				fl = 1;
		}
		cout << fl << " ";
	}
	cout << "\n";
	return 0;
}