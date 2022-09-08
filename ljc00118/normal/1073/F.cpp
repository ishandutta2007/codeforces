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

const int N = 2e5 + 5;

vector <int> adj[N];
int d[N], f[N][2];
int n, ans, a, b;

void dfs1(int u, int fa) {
	f[u][0] = f[u][1] = -1;
	for(register int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(v == fa) continue; d[v] = d[u] + 1; dfs1(v, u);
		if(f[u][0] == -1 || (f[u][0] != -1 && d[f[u][0]] < d[f[v][0]])) f[u][1] = f[u][0], f[u][0] = f[v][0];
		else if(f[u][1] == -1 || (f[u][1] != -1 && d[f[u][1]] < d[f[v][0]])) f[u][1] = f[v][0];
	}
	if(f[u][0] == -1) f[u][0] = u; else if(f[u][1] != -1) {
		if(ans == -1) ans = u;
		else if(d[u] > d[ans]) ans = u;
		else if(d[u] == d[ans] && d[f[u][0]] + d[f[u][1]] - d[f[ans][0]] - d[f[ans][1]] > 2 * (d[u] - d[ans])) ans = u;
	}
}

int main() {
	read(n);
	for(register int i = 1; i < n; i++) {
		int a, b; read(a); read(b);
		adj[a].push_back(b);
		adj[b].push_back(a); 
	}
	ans = -1; dfs1(1, 0); a = f[ans][0]; b = f[ans][1]; int t = ans; ans = -1; d[t] = 0; dfs1(t, 0);
	print(a, ' '); print(f[ans][0], '\n'); print(b, ' '); print(f[ans][1], '\n');
	return 0;
}