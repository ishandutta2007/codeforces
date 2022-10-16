#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 200005, M = 300005, Q = 500005;

int n, m, q, p[N], Opt[Q], V[Q], pos[N], d[N], tot;

int f[N], sz[N], top, X[M], Y[M];

bool del[N];

vector<int> id[N];

struct E{
	int a, b;
} e[M];
 
bool st[M], vis[Q];

int find(int x) {
	return x == f[x] ? x : find(f[x]);
}

void merge(int x, int y, int i) {
	x = find(x), y = find(y);
	if (x == y) return;
	vis[i] = true;
	if (sz[x] > sz[y]) swap(x, y);
	f[x] = y, sz[y] += sz[x];
	for (int i = 0; i < sz[x]; i++)
		id[y].push_back(id[x][i]), pos[id[x][i]] = y;
	X[++top] = x, Y[top] = y;
}

void inline pop() {
	int x = X[top], y = Y[top]; top--;
	f[x] = x, sz[y] -= sz[x];
	for (int i = 0; i < id[x].size(); i++)
		pos[id[x][i]] = x;
}

int inline get(int x) {
	x = find(x);
	while (id[x].size() && (pos[id[x][id[x].size() - 1]] != x || del[id[x][id[x].size() - 1]])) id[x].pop_back();
	if (id[x].size() == 0) return 0;
	del[id[x][id[x].size() - 1]] = true;
	return p[id[x][id[x].size() - 1]];
}

bool inline cmp(int x, int y) {
	return p[x] < p[y];
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) scanf("%d", p + i);
	for (int i = 1; i <= m; i++) scanf("%d%d", &e[i].a, &e[i].b);
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", Opt + i, V + i);
		if (Opt[i] == 2) {
			st[V[i]] = true;
		}  
	}
	for (int i = 1; i <= n; i++) {
		f[i] = i, sz[i] = 1, pos[i] = i, id[i].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		if (!st[i]) merge(e[i].a, e[i].b, 0);
	}
	for (int i = q; i; i--) 
		if (Opt[i] == 2) merge(e[V[i]].a, e[V[i]].b, i);
	
	for (int i = 1; i <= n; i++) sort(id[i].begin(), id[i].end(), cmp);

	for (int i = 1; i <= q; i++) {
		if (Opt[i] == 1) {
			printf("%d\n", get(V[i]));
		} else if (vis[i]) pop();
	}
	return 0;
}