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

const int N = 2345678, INF = 0x7fffffff;

vector <int> adj[N];
int mn[N], f[N][2];
int n, k;

void dfs1(int u) {
	mn[u] = INF; f[u][1] = 0;
	for(register int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i]; dfs1(v);
		mn[u] = min(mn[u], mn[v] + 1);
		f[u][0] += f[v][0];
		f[u][1] = max(f[u][1], f[v][1] - f[v][0]);
	}
	f[u][1] += f[u][0];
	if(mn[u] == INF) f[u][0] = f[u][1] = 1, mn[u] = 0;
	if(mn[u] >= k) f[u][0] = 0;
}

int main() {
	read(n); read(k);
	for(register int i = 2; i <= n; i++) {
		int a; read(a);
		adj[a].push_back(i);
	}
	dfs1(1); print(f[1][1], '\n');
	return 0;
}