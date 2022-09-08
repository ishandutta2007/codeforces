#include <bits/stdc++.h>
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

vector <int> adj[N];
ll f[N], g[N], maxn = -0x7fffffff;
int w[N];
int n;

void dfs1(int u, int fa) {
	f[u] = w[u]; int cnt = 0;
	for(register int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i]; if(v == fa) continue;
		dfs1(v, u); if(f[v] >= 0) f[u] += f[v], cnt++;
	}
	maxn = max(maxn, f[u]);
}

void dfs2(int u, int fa) {
	f[u] = w[u]; g[u] = 0; ll sum = 0; int cnt = 0;
	for(register int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i]; if(v == fa) continue;
		dfs2(v, u); g[u] += g[v]; 
		if(f[v] >= 0) sum += f[v], cnt++;
	}
	if(f[u] + sum == maxn) f[u] = -0x7fffffff, g[u]++;
	else f[u] += sum;
}

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(w[i]);
	for(register int i = 1; i < n; i++) {
		int a, b; read(a); read(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(1, 0); dfs2(1, 0);
	print(g[1] * maxn, ' '); print(g[1], '\n');
	return 0;
}