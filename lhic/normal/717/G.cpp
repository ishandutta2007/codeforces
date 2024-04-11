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

struct edge {
	int a, b, w, c, f;
};

struct edd {
	int a, b, w, n;
	edd(int A, int B, int W, int N) {
		a = A, b = B, w = W, n = N;
	}
};
const int MAXN = 510;

vector<int> eds[MAXN];
int was[MAXN];
vector<edge> ed;
int n;
string s;
int m;
string t[MAXN];
pair<int, string> tt[MAXN];
int cs[MAXN];
int go[MAXN];
int dd[MAXN];
int gg[MAXN];

void make_edge(int a, int b, int w, int fl) {
	edge x;
	x.a = a;
	x.b = b;
	x.c = 1;
	x.w = w;
	if (!fl)
		x.f = 0;
	else
		x.f = x.c;
	eds[a].push_back(ed.size());
	ed.push_back(x);
	swap(x.a, x.b);
	x.c = 0;
	x.f = -x.f;
	x.w = -x.w;
	eds[b].push_back(ed.size());
	ed.push_back(x);
}

vector<edd> vv;

int main() {
	ll ans = 0;
	cin >> n;
	cin >> s;
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> tt[i].second >> tt[i].first;
	sort(tt, tt + m);
	reverse(tt, tt + m);
	int x;
	cin >> x;
	for (int j = 0; j < n; ++j)
		go[j] = x;
	for (int i = 0; i < m; ++i) {
		t[i] = tt[i].second;
		cs[i] = tt[i].first;
		for (int j = 0; j <= (int)(s.size() - t[i].size()); ++j) {
			int fl = 0;
			for (int k = 0; k < (int)t[i].size(); ++k)
				if (s[j + k] != t[i][k]) {
					fl = 1;
					break;
				}
			if (fl)
				continue;
			for (int k = j; k < j + (int)t[i].size(); ++k)
				if (go[k] == 0)
					fl = 1;
			if (!fl) {
				for (int k = j; k < j + (int)t[i].size(); ++k)
					--go[k];
				make_edge(j + t[i].size(), j, -cs[i], 1);
				ans -= cs[i];
			}
			else {
				make_edge(j + t[i].size(), j, -cs[i], 0);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		edge xx;
		xx.a = i;
		xx.b = i + 1;
		xx.c = x;
		xx.w = 0;
		xx.f = x - go[i];
		eds[i].push_back(ed.size());
		ed.push_back(xx);
		swap(xx.a, xx.b);
		xx.c = 0;
		xx.f = -xx.f;
		eds[i + 1].push_back(ed.size());
		ed.push_back(xx);
	}
	vector<int> way;
	while (true) {
		for (int i = 0; i < n + 1; ++i)
			dd[i] = 0, gg[i] = -1;
		vv.clear();
		for (int i = 0; i < (int)ed.size(); ++i) {
			if (ed[i].f != ed[i].c)
				vv.push_back(edd(ed[i].a, ed[i].b, ed[i].w, i));
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < (int)vv.size(); ++j)
				if (dd[vv[j].b] > dd[vv[j].a] + vv[j].w) {
					dd[vv[j].b] = dd[vv[j].a] + vv[j].w;
					gg[vv[j].b] = j;
				}
		}
		int fl = 0;
		fill(was, was + n + 1, -1);
		way.clear();
		for (int j = 0; j < (int)vv.size(); ++j)
			if (dd[vv[j].b] > dd[vv[j].a] + vv[j].w) {
				dd[vv[j].b] = dd[vv[j].a] + vv[j].w;
				gg[vv[j].b] = j;
				int now = vv[j].b;
				fl = 1;
				while (was[now] == -1) {
					was[now] = way.size();
					way.push_back(vv[gg[now]].n);
					now = vv[gg[now]].a;
				}
				for (int i = was[now]; i < (int)way.size(); ++i) {
					int e = way[i];
					ans += ed[e].w;
					ed[e].f += 1;
					ed[e ^ 1].f -= 1;
				}
				break;
			}
		if (!fl)
			break;
	}
	cout << -ans << "\n";
	return 0;
}