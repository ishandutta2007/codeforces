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


struct edge {
	int a, b, c, f;
};

int n, m, k;
vector<tuple<int, int, int> > ed2;
vector<edge> ed;
int was[52];
vector<int> eds[52];

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

int flow(int v, int fl) {
	if (v == n - 1)
		return fl;
	was[v] = 1;
	for (int e: eds[v]) {
		int u = ed[e].b;
		int w = ed[e].c - ed[e].f;
		if (!w)
			continue;
		if (was[u])
			continue;
		int go = flow(u, min(fl, w));
		if (go) {
			ed[e].f += go;
			ed[e ^ 1].f -= go;
			return go;
		}
	}
	return 0;
}


int check(ld x) {
	for (int i = 0; i < n; ++i)
		eds[i].clear();
	ed.clear();

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		tie(a, b, c) = ed2[i];
		int go = min(200000.0l, c / x);
		make_edge(a, b, go);
	}
	int ans = 0;
	while (true) {
		memset(was, 0, sizeof(was));
		int x = flow(0, 2000000);
		if (x == 0)
			break;
		ans += x;
		if (ans >= k)
			return 1;
	}
	return 0;
}


int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		ed2.push_back(make_tuple(a, b, c));
	}
	ld lb = 0;
	ld rb = 1000000;
	for (int it = 0; it < 100; ++it) {
		ld mid = (lb + rb) / 2;
		if (check(mid))
			lb = mid;
		else
			rb = mid;
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << k * ((lb + rb) / 2) << "\n";
	return 0;
}