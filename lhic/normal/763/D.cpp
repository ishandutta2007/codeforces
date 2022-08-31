
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

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}

int cc = 1;
int cnt;
int bstcnt;
int bst;
typedef unsigned long long hsh;
const int MAXN = 120000;

const hsh P = 1000000007;
map<hsh, int> mm;
map<int, int> mc;
vector<int> eds[MAXN];
int hs[MAXN];
vector<int> hss[MAXN];
int gl[MAXN];
int was[MAXN];
hsh pw[MAXN];

int get(hsh x) {
	if (mm.count(x))
		return mm[x];
	else
		return mm[x] = cc++;
}

void add(int x) {
	++mc[x];
	if (mc[x] == 1)
		++cnt;
}

void del(int x) {
	--mc[x];
	if (mc[x] == 0)
		--cnt;
}

void dfs1(int v) {
	was[v] = 1;
	vector<int> vv;
	for (int u: eds[v]) {
		if (!was[u])
			dfs1(u), vv.push_back(hs[u]);
	}
	sort(vv.begin(), vv.end());
	hsh now = 0;
	for (int i = 0; i < vv.size(); ++i)
		now = now * P + vv[i];
	hs[v] = get(now);
}

void dfs2(int v, int up) {
	was[v] = 1;
	vector<pair<int, int> > vv;
	if (up != -1)
		vv.push_back(make_pair(up, -1));
	for (int i = 0; i < eds[v].size(); ++i) {
		int u = eds[v][i];
		if (!was[u])
			vv.push_back(make_pair(hs[u], i));
	}
	sort(vv.begin(), vv.end());
	hsh now = 0;
	for (int i = 0; i < vv.size(); ++i)
		now = now * P + vv[i].first;
	gl[v] = get(now);
	hsh now2 = 0;
	hss[v].resize(eds[v].size(), -1);
	for (int i = 0; i < vv.size(); ++i) {
		now = now - pw[vv.size() - i - 1] * vv[i].first;
		if (vv[i].second != -1) {
			hss[v][vv[i].second] = get(now2 + now);
			dfs2(eds[v][vv[i].second], hss[v][vv[i].second]);
		}
		if (i != vv.size() - 1)
			now2 = now2 + pw[vv.size() - i - 2] * vv[i].first;
	}
}

void dfs3(int v) {
	if (cnt > bstcnt)
		bstcnt = cnt, bst = v;
	was[v] = 1;
	for (int i = 0; i < eds[v].size(); ++i) {
		int u = eds[v][i];
		if (!was[u]) {
			del(gl[v]);
			add(gl[u]);
			del(hs[u]);
			add(hss[v][i]);
			dfs3(u);
			add(gl[v]);
			del(gl[u]);
			add(hs[u]);
			del(hss[v][i]);
		}
	}
}

int n;
int main() {
	pw[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		pw[i] = (pw[i - 1] * P);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0);
	memset(was, 0, sizeof(was));
	dfs2(0, -1);
	memset(was, 0, sizeof(was));
	bst = 0;
	for (int i = 0; i < n; ++i)
		add(hs[i]);
	bstcnt = cnt;
	dfs3(0);
	cout << bst + 1 << "\n";
	return 0;
}