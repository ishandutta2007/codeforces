#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
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

const int N = 1e5 + 5;

struct Edge {
	int u, v, next;
}G[N << 1];

int head[N], cnt[N], siz[N], ans[N];
int n, tot;

inline void addedge(int u, int v) { G[++tot] = (Edge) {u, v, head[u]}, head[u] = tot; }

void dfs1(int u) {
	if(!head[u]) siz[u] = 1;
	else {
		for(register int i = head[u]; i; i = G[i].next) {
			int v = G[i].v; dfs1(v);
			siz[u] += siz[v];
		}
	}
	cnt[siz[u]]++;
}

int main() {
	read(n);
	for(register int i = 2; i <= n; i++) { int a; read(a); addedge(a, i); }
	dfs1(1); for(register int i = 2; i <= n; i++) cnt[i] += cnt[i - 1];
	for(register int i = 1; i <= n; i++) {
		for(register int j = cnt[i - 1] + 1; j <= cnt[i]; j++) ans[j] = i;
	}
	for(register int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
	return 0;
}