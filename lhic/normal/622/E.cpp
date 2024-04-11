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

int was[MAXN];
int sz[MAXN];
int n;
vector<int> eds[MAXN];
int h[MAXN];

void dfs(int v) {
	sz[v] = 1;
	was[v] = 1;
	for (int u: eds[v])
		if (!was[u]) {
			h[u] = h[v] + 1;
			dfs(u);
			sz[v] += sz[u];
		}
}


int mx = 0;
set<int> ss;

void dfs2(int v) {
	was[v] = 1;
	if (sz[v] == 1) {
		auto it = ss.lower_bound(h[v]);
		mx = max(mx, *it);
		ss.erase(it);
	}
	else {
		for (int u: eds[v])
			if (!was[u])
				dfs2(u);
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
	dfs(0);
	memset(was, 0, sizeof(was[0]) * n);
	was[0] = 1;
	for (int v: eds[0]) {
		ss.clear();
		for (int i = 1; i <= sz[v] * 2 + 10; ++i)
			ss.insert(i);
		dfs2(v);
	}
	printf("%d\n", mx);
	return 0;
}