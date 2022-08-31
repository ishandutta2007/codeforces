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
const int MAXN = 300000;

struct edge {
	int a, b;
	int f, c;
};

vector<edge> ed;
vector<int> eds[MAXN];
int dd[MAXN];
int pp[MAXN];
int n, m;

void make_edge(int a, int b, int c) {
	edge x;
	x.a = a, x.b = b, x.c = c;
	x.f = 0;
	eds[a].push_back(ed.size());
	ed.push_back(x);
	swap(x.a, x.b);
	x.c = 0;
	eds[b].push_back(ed.size());
	ed.push_back(x);
}

int dfs(int v, int fl, int t) {
	if (v == t)
		return fl;
	if (dd[v] >= dd[t])
		return 0;
	int now = 0;
	for (; pp[v] < (int)eds[v].size(); ++pp[v]) {
		int e = eds[v][pp[v]];
		int u = ed[e].b;
		int go = ed[e].c - ed[e].f;
		if (go == 0)
			continue;
		if (dd[u] != dd[v] + 1)
			continue;
		go = dfs(u, min(fl, go), t);
		fl -= go;
		now += go;
		ed[e].f += go;
		ed[e ^ 1].f -= go;
		if (!fl)
			break;
	}
	return now;
}

int dinic(int n, int s, int t) {
	fill(dd, dd + n, MAXN);
	dd[s] = 0;
	queue<int> qu;
	qu.push(s);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int e: eds[x]) {
			int u = ed[e].b;
			if (dd[u] > dd[x] + 1 && ed[e].f < ed[e].c)
				dd[u] = dd[x] + 1, qu.push(u);
		}
	}
	if (dd[t] >= MAXN)
		return 0;
	fill(pp, pp + n, 0);
	return dfs(s, MAXN, t);
}

int flow(int n, int s, int t) {
	int ans = 0;
	while (true) {
		int x = dinic(n, s, t);
		if (!x)
			break;
		ans += x;
	}
	return ans;
}


int x[MAXN];
int y[MAXN];
vector<int> vvx;
vector<int> vvy;
int ccx[MAXN];
int ccy[MAXN];
int lbx[MAXN];
int rbx[MAXN];
int lby[MAXN];
int rby[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	ll r, b;
	scanf("%lld%lld", &r, &b);
	ll ans = max(r, b) * n;
	ll dl = max(r, b) - min(r, b);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x + i, y + i);
		vvx.push_back(x[i]);
		vvy.push_back(y[i]);
	}
	sort(vvx.begin(), vvx.end());
	vvx.resize(unique(vvx.begin(), vvx.end()) - vvx.begin());
	sort(vvy.begin(), vvy.end());
	vvy.resize(unique(vvy.begin(), vvy.end()) - vvy.begin());
	for (int i = 0; i < n; ++i)
		x[i] = lower_bound(vvx.begin(), vvx.end(), x[i]) - vvx.begin();
	for (int i = 0; i < n; ++i)
		y[i] = lower_bound(vvy.begin(), vvy.end(), y[i]) - vvy.begin();
	for (int i = 0; i < n; ++i)
		ccx[x[i]]++, ccy[y[i]]++;
	for (int i = 0; i < (int)vvx.size(); ++i)
		lbx[i] = 0, rbx[i] = ccx[i];
	for (int i = 0; i < (int)vvy.size(); ++i)
		lby[i] = 0, rby[i] = ccy[i];
	for (int i = 0; i < m; ++i) {
		int t, l, d;
		scanf("%d%d%d", &t, &l, &d);
		if (t == 1) {
			if (!binary_search(vvx.begin(), vvx.end(), l))
				continue;
			l = lower_bound(vvx.begin(), vvx.end(), l) - vvx.begin();
			rbx[l] = min(rbx[l], (ccx[l] + d) / 2);
			lbx[l] = max(lbx[l], ccx[l] - rbx[l]);
		}
		else {
			if (!binary_search(vvy.begin(), vvy.end(), l))
				continue;
			l = lower_bound(vvy.begin(), vvy.end(), l) - vvy.begin();
			rby[l] = min(rby[l], (ccy[l] + d) / 2);
			lby[l] = max(lby[l], ccy[l] - rby[l]);
		}
	}
	for (int i = 0; i < (int)vvx.size(); ++i) {
		if (lbx[i] > rbx[i]) {
			cout << -1 << "\n";
			return 0;
		}
	}
	for (int i = 0; i < (int)vvy.size(); ++i) {
		if (lby[i] > rby[i]) {
			cout << -1 << "\n";
			return 0;
		}
	}
	int s, t;
	s = 2 + vvx.size() + vvy.size();
	t = s + 1;
	make_edge(1, 0, MAXN * 5);
	for (int i = 0; i < n; ++i)
		make_edge(x[i] + 2, y[i] + 2 + vvx.size(), 1);
	int nd = 0;
	for (int i = 0; i < (int)vvx.size(); ++i) {
		int l = rbx[i] - lbx[i];
		int d = lbx[i];
		make_edge(0, i + 2, l);
		make_edge(0, t, d);
		make_edge(s, i + 2, d);
		nd += d;
	}
	for (int i = 0; i < (int)vvy.size(); ++i) {
		int l = rby[i] - lby[i];
		int d = lby[i];
		make_edge(i + 2 + vvx.size(), 1, l);
		make_edge(i + 2 + vvx.size(), t, d);
		make_edge(s, 1, d);
		nd += d;
	}
	int fl = flow(t + 1, s, t);
	if (fl != nd) {
		cout << -1 << "\n";
	}
	int now = ed[0].f;
	vector<edge> tmp;
	for (int i = 0; i <= t; ++i)
		eds[i].clear();
	for (int i = 2; i < (int)ed.size(); ++i) {
		int a = ed[i].a, b = ed[i].b;
		if (b == s || a == s || b == t || a == t)
			continue;
		eds[a].push_back(tmp.size());
		tmp.push_back(ed[i]);
	}
	ed = tmp;
	now += flow(s, 0, 1);
	ans -= now * dl;
	cout << ans << "\n";
	for (int i = 0; i < n; ++i) {
		if (ed[i * 2].f == 1) {
			if (r < b)
				printf("r");
			else
				printf("b");
		}
		else {
			if (r < b)
				printf("b");
			else
				printf("r");
		}
	}
	printf("\n");
	return 0;
}