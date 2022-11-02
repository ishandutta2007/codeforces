// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 4e5 + 5;

int n, f[60], cnt[N], sz[N];

int head[N], numE = 1, S;

bool vis[N];

struct E{
	int next, v;
} e[N << 1];

int st[N];

void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}

int SS;

vector<int> A[60], B[60], ID[60], X[60];

void dfs(int u, int fa) {
	sz[u] = 1;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == fa || vis[i >> 1]) continue;
		dfs(v, u);
		if (sz[v] == f[S - 1] || sz[v] == f[S - 2]) {
			A[SS].push_back(u);
			B[SS].push_back(v);
			ID[SS].push_back(i >> 1);
			X[SS].push_back(st[sz[v]]);
		}
		sz[u] += sz[v];
	}
}

bool work(int rt, int k) {
	A[k].clear(); B[k].clear(), X[k].clear(), ID[k].clear();
	
	SS = k;
	//cout << " Join " << rt << " " << k << endl;
	if (k <= 2) return true;
	S = k;
	dfs(rt, 0);
	//cout << U << " " << V<< endl;
	int t = k;
	for (int i = 0; i < A[t].size(); i++) {
		int U = A[t][i], V = B[t][i];
		int id = ID[t][i];
		int y = X[t][i], x = 2 * k - 3 - y;
		vis[id] = true;
		if (work(U, x) && work(V, y)) {
			vis[id] = false;
			return true; 
		}
		vis[id] = false;
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	f[0] = f[1] = 1;
	for (int i = 2; i <= 26; i++) f[i] = f[i - 1] + f[i - 2];
	for (int i = 1; i <= 26; i++) st[f[i]] = i;
	if (!st[n]) puts("NO");
	else {
		puts(work(1, st[n]) ? "YES" : "NO");
	}
	return 0;
}