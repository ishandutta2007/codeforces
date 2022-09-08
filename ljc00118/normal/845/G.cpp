#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
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

const int N = 100005, M = 100005;

struct Edge {
	int u, v, next;
	ll val;
}G[M << 1];

ll p[100], dis[N];
int head[N], vis[N];
int n, m, tot;

inline void addedge(int u, int v, ll val) {
	G[++tot] = (Edge) {u, v, head[u], val}, head[u] = tot;
	G[++tot] = (Edge) {v, u, head[v], val}, head[v] = tot;
}

void ins(ll x) {
	Rof(i, 63, 0) {
		if(x & (1ll << i)) {
			if(!p[i]) {
				p[i] = x;
				break;
			}
			x ^= p[i]; 
		}
	}
}

ll qry(ll x) {
	Rof(i, 63, 0) if((x ^ p[i]) < x) x ^= p[i];
	return x;
}

void dfs(int u, ll cur) {
	dis[u] = cur; vis[u] = 1;
	for(register int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if(!vis[v]) dfs(v, cur ^ G[i].val);
		else ins(cur ^ G[i].val ^ dis[v]);
	}
}

int main() {
	read(n); read(m);
	while(m--) {
		int a, b; ll c;
		read(a); read(b); read(c);
		addedge(a, b, c);
	}
	dfs(1, 0); print(qry(dis[n]), '\n');
	return 0;
}