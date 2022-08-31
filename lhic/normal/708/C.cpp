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
const int MAXN = 510000;
int n;
int sz[MAXN];
int was[MAXN];
int up[MAXN];
vector<int> eds[MAXN];
int ans[MAXN];

void dfs1(int v) {
	sz[v] = 1;
	was[v] = 1;
	for (int u: eds[v]) {
		if (!was[u]) {
			dfs1(u);
			sz[v] += sz[u];
		}
	}
}

void dfs2(int v) {
	was[v] = 1;
	up[v] = 0;
	if (sz[v] * 2 <= n)
		up[v] = sz[v];
	for (int u: eds[v]) {
		if (!was[u]) {
			dfs2(u);
			up[v] = max(up[v], up[u]);
		}
	}
}


void dfs3(int v, int now) {
	ans[v] = 1;
	was[v] = 1;
	if ((n - sz[v]) * 2 <= n)
		now = max(now, n - sz[v]);
	if ((n - sz[v] - now) * 2 > n)
		ans[v] = 0;
	int mx1 = 0;
	int mx2 = 0;
	for (int u: eds[v]) {
		if (!was[u]) {
			mx2 = max(mx2, up[u]);
			if (mx2 > mx1)
				swap(mx1, mx2);
		}
	}
	for (int u: eds[v]) {
		if (!was[u]) {
			if ((sz[u] - up[u]) * 2 > n)
				ans[v] = 0;
			int go = now;
			if (up[u] == mx1)
				go = max(now, mx2);
			else
				go = max(now, mx1);
			dfs3(u, go);
		}
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0);
	memset(was, 0, sizeof(was));
	dfs2(0);
	memset(was, 0, sizeof(was));
	dfs3(0, 0);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}