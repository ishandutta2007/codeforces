#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Forr(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 4e5 + 5;

struct Node { int l, r, tag; ll val; } p[N << 2];
struct Edge { int u, v, next; } G[N << 1];

int a[N], tops[N], pre[N], siz[N], head[N];
int n, m, tot, cnt;

inline void addedge(int u, int v) {
	G[++tot] = (Edge) {u, v, head[u]}, head[u] = tot;
	G[++tot] = (Edge) {v, u, head[v]}, head[v] = tot;
}

void dfs1(int u, int f) {
	siz[u] = 1; tops[u] = ++cnt; pre[cnt] = u;
	for(register int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if(v == f) continue;
		dfs1(v, u); siz[u] += siz[v];
	}
}

void update(int u) { p[u].val = p[u << 1].val | p[u << 1 | 1].val; }

void pushdown(int u) {
	if(p[u].tag) {
		p[u << 1].val = p[u << 1 | 1].val = (1ll << p[u].tag - 1);
		p[u << 1].tag = p[u << 1 | 1].tag = p[u].tag;
		p[u].tag = 0;
	}
}

void build(int u, int l, int r) {
	p[u].l = l; p[u].r = r; p[u].tag = 0;
	if(l == r) {
		p[u].val = (1ll << a[pre[l]] - 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	update(u);
}

void change(int u, int l, int r, int x) {
	if(p[u].l >= l && p[u].r <= r) {
		p[u].val = (1ll << x - 1);
		p[u].tag = x;
		return;
	}
	pushdown(u); 
	int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= l) change(u << 1, l, r, x);
	if(mid + 1 <= r) change(u << 1 | 1, l, r, x);
	update(u);
}

ll query(int u, int l, int r) {
	if(p[u].l >= l && p[u].r <= r) return p[u].val;
	pushdown(u); ll ans = 0;
	int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= l) ans |= query(u << 1, l, r);
	if(mid + 1 <= r) ans |= query(u << 1 | 1, l, r);
	return ans;
} 

int calc(ll x) {
	int ans = 0;
	while(x) {
		ans++;
		x -= (x & -x);
	}
	return ans;
}

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n; i++) read(a[i]);
	for(register int i = 1; i < n; i++) {
		int a, b; read(a); read(b);
		addedge(a, b);
	}
	dfs1(1, 0); build(1, 1, n);
	while(m--) {
		int opt; read(opt);
		if(opt == 1) {
			int a, b; read(a); read(b);
			change(1, tops[a], tops[a] + siz[a] - 1, b);
		} else {
			int x; read(x);
			print(calc(query(1, tops[x], tops[x] + siz[x] - 1)), '\n');
		}
	}
	return 0;
}