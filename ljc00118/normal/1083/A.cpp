#include <bits/stdc++.h>
#define int long long
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
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

const int N = 3e5 + 5;

struct Edge {
	int u, v, next, val;
}G[N << 1];

int head[N];
int f[N][2], w[N];
int n, tot, ans = 0;

inline void addedge(int u, int v, int val) {
	G[++tot] = (Edge) {u, v, head[u], val}, head[u] = tot;
	G[++tot] = (Edge) {v, u, head[v], val}, head[v] = tot;
}

void dfs1(int u, int fa) {
	f[u][0] = f[u][1] = w[u];
	for(register int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if(v == fa) continue;
		dfs1(v, u);
		int val1 = f[v][0] - G[i].val + w[u], val2 = val1 - f[v][0] + f[v][1];
		if(val1 >= f[u][0]) {
			f[u][1] = f[u][0];
			f[u][0] = val1;
		} else if(val1 >= f[u][1]) {
			f[u][1] = val1;
		}
	}
	ans = max(ans, f[u][0]);
	ans = max(ans, f[u][0] + f[u][1] - w[u]);
}

#undef int
int main() {
#define int long long
	read(n);
	for(register int i = 1; i <= n; i++) read(w[i]);
	for(register int i = 1; i < n; i++) {
		int a, b, c;
		read(a); read(b); read(c); 
		addedge(a, b, c);
	}
	dfs1(1, 0); cout << ans << endl;
	return 0;
}