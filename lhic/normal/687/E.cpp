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
const int MAXN = 5100;
const int INF = 100000;

int was[MAXN];
vector<int> eds[MAXN];
vector<int> reds[MAXN];
vector<int> vv;
int cl[MAXN];
vector<pair<int, int> > ed;
vector<int> gg[MAXN];
int fl[MAXN];
int n;
int m;
int cc;



void dfs1(int v) {
	was[v] = 1;
	for (int u: eds[v]) {
		if (!was[u])
			dfs1(u);
	}
	vv.push_back(v);
}

void dfs2(int v, int c) {
	cl[v] = c;
	was[v] = 1;
	gg[c].push_back(v);
	for (int u: reds[v]) {
		if (!was[u])
			dfs2(u, c);
	}
}

int dd[MAXN];

int solve(vector<int> vv) {
	int mn = n + 1000;
	for (int x: vv) {
		fill(dd, dd + n, INF);
		dd[x] = 0;
		queue<int> qu;
		qu.push(x);
		while (!qu.empty()) {
			int v = qu.front();
			qu.pop();
			for (int u: eds[v])
				if (dd[u] > dd[v] + 1) {
					dd[u] = dd[v] + 1;
					qu.push(u);
				}
			if (dd[v] == 0)
				dd[v] = INF;
		}
		mn = min(mn, dd[x]);
	}
	return mn;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		reds[b].push_back(a);
		ed.push_back(make_pair(a, b));
	}
	for (int i = 0; i < n; ++i)
		if (!was[i])
			dfs1(i);
	reverse(vv.begin(), vv.end());
	memset(was, 0, sizeof(was));
	for (int i = 0; i < n; ++i) {
		int v = vv[i];
		if (was[v])
			continue;
		dfs2(v, cc++);
	}
	for (int i = 0; i < m; ++i) {
		if (cl[ed[i].first] != cl[ed[i].second])
			fl[cl[ed[i].first]] = 1;
	}
	int ans = n;
	for (int i = 0; i < cc; ++i) {
		if (fl[i])
			continue;
		if (gg[i].size() == 1)
			continue;
		int len = solve(gg[i]);
		ans += 1 + len * 998;
	}
	cout << ans << "\n";

	return 0;
}