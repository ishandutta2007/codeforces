#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#define mp make_pair
using namespace std;

const int N = 500005;

int n, m, U[N], V[N], C[N], T[N], dfn[N], low[N], s[N], top, col[N], cnt;

int dfncnt;

int pos[N], pre[N], suf[N], pos2[N];

int A[N], B[N], idx;

bool ins[N];

map<pair<int, int>, int> g, g2;

int t1[N], t2[N];


int head[N], numE = 0;

struct E{
	int next, v;
} e[N * 7];

void tarjan(int u) {
    dfn[u] = low[u] = ++dfncnt;
    s[++top] = u, ins[u] = true;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (!dfn[v]) {
            tarjan(v), low[u] = min(low[u], low[v]);
        } else if (ins[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        int v; ++cnt;
        do {
            v = s[top--], ins[v] = false, col[v] = cnt;
        } while (v != u);
    }
}


bool inline work(int len) {
	memset(ins, 0, sizeof ins);
	memset(dfn, 0, sizeof dfn);
	top = cnt = 0; 
	for (int i = 1; i <= len; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= m; i++)
		if (col[i + m] == col[i]) return false;
	return true;
}

void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}

bool inline check(int x) {
	memset(head, 0, sizeof head);
	numE = 1;
	for (int i = 1; i <= m; i++) {
		if (T[i] > x) add(i + m, i);
	}
	
	for (int i = 2 * m + 1; i <= idx; i++) {
		if (pos[i]) {
			add(i, pos[i] + m);
			if (pre[i]) add(pos[i], pre[i]);
			if (suf[i]) add(pos[i], suf[i]);
		} else {
			add(i, pos2[i]);
			if (pre[i]) add(pos2[i] + m, pre[i]);
			if (suf[i]) add(pos2[i] + m, suf[i]);
		}
		if (pre[i]) add(i, pre[i]);
		if (suf[i]) add(i, suf[i]);
	}
	return work(idx);	
}

void inline add2(int x, int c, int v) {
	++idx; pos[idx] = v;
	if (g.count(make_pair(x, c))) {
		pre[idx] = g[mp(x, c)];
	} 
	g[mp(x, c)] = idx;
	
	
	++idx;
	if (g2.count(make_pair(x, c))) {
		suf[g2[mp(x, c)]] = idx;	
	}
	pos[idx] = v;
	g2[mp(x, c)] = idx;
	
	++idx;
	if (t1[x]) {
		pre[idx] = t1[x];
	}
	pos2[idx] = v;
	t1[x] = idx;
	++idx;
	if (t2[x]) {
		suf[t2[x]] = idx;
	}
	pos2[idx] = v;
	t2[x] = idx;
}

int main() {
	scanf("%d%d", &n, &m); idx = 2 * m;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", U + i, V + i, C + i, T + i);
		add2(U[i], C[i], i);
		add2(V[i], C[i], i);
	}
	
	
	
	int l = 0, r = 1e9;
	
	if (!check(r)) {
		puts("No"); return 0;
	}
	
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	puts("Yes");
	check(r);
	printf("%d ", r);
	int cnt = 0;
	for (int i = 1; i <= m; i++)
		cnt += col[i] > col[i + m];
	printf("%d\n", cnt);
	for (int i = 1; i <= m; i++)
		if (col[i] > col[i + m]) printf("%d ", i);
	return 0;
}