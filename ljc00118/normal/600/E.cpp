#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e5 + 5;

struct Node {
	int lc, rc, maxn; ll sum;
}p[N * 60];

vector <int> adj[N];
int w[N], rt[N]; ll Ans[N];
int n, tot;

void update(int u) {
	if(p[u].lc == 0) p[u].maxn = p[p[u].rc].maxn, p[u].sum = p[p[u].rc].sum;
	else if(p[u].rc == 0) p[u].maxn = p[p[u].lc].maxn, p[u].sum = p[p[u].lc].sum;
	else {
		if(p[p[u].lc].maxn > p[p[u].rc].maxn) {
			p[u].maxn = p[p[u].lc].maxn;
			p[u].sum = p[p[u].lc].sum;
		}
		if(p[p[u].lc].maxn < p[p[u].rc].maxn) {
			p[u].maxn = p[p[u].rc].maxn;
			p[u].sum = p[p[u].rc].sum;
		}
		if(p[p[u].lc].maxn == p[p[u].rc].maxn) {
			p[u].maxn = p[p[u].lc].maxn;
			p[u].sum = p[p[u].lc].sum + p[p[u].rc].sum;
		}
	}
}

void ins(int &u, int l, int r, int x) {
	if(!u) u = ++tot;
	if(l == r) {
		p[u].maxn++;
		p[u].sum = x;
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= x) ins(p[u].lc, l, mid, x);
	else ins(p[u].rc, mid + 1, r, x);
	update(u);
}

void merge(int u, int v, int l, int r) {
	if(l == r) {
		p[u].maxn = p[u].maxn + p[v].maxn;
		p[u].sum = max(p[u].sum, p[v].sum);
		return;
	}
	int mid = (l + r) >> 1;
	if(p[u].lc && p[v].lc) merge(p[u].lc, p[v].lc, l, mid); else if(p[v].lc) p[u].lc = p[v].lc;
	if(p[u].rc && p[v].rc) merge(p[u].rc, p[v].rc, mid + 1, r); else if(p[v].rc) p[u].rc = p[v].rc;
	update(u);
}

void dfs1(int u, int fa) {
	ins(rt[u], 1, 100000, w[u]);
	for(register int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i]; if(v == fa) continue; dfs1(v, u);
		merge(rt[u], rt[v], 1, 100000);
	}
	Ans[u] = p[rt[u]].sum;
}

int main() {
	read(n); tot = n + 1;
	for(register int i = 1; i <= n; i++) rt[i] = i;
	for(register int i = 1; i <= n; i++) read(w[i]); 
	for(register int i = 1; i < n; i++) {
		int a, b; read(a); read(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(1, 0);
	for(register int i = 1; i <= n; i++) print(Ans[i], i == n ? '\n' : ' ');
	return 0;
}