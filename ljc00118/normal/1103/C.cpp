#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
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

const int N = 250005;

vector <int> adj[N];
int dep[N], fa[N], leaf[N];
int n, m, k, maxn = 1;

void dfs1(int u) {
	if(dep[u] > dep[maxn]) { maxn = u; } leaf[u] = 1;
	for(register unsigned i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i]; if(!dep[v]) {
			dep[v] = dep[u] + 1;
			fa[v] = u; dfs1(v); leaf[u] = 0;
		}
	}
}

bool check(int x, int y, int z) {
	int dis = dep[y] - dep[z] + 2;
	if(dis <= 3 || dis % 3 == 0) return 0;
	return 1;
}

void calc(int x, int y, int z) {
	print(2 + dep[y] - dep[z], '\n');
	print(x, ' ');
	while(y != z) {
		print(y, ' ');
		y = fa[y];
	}
	print(z, '\n');
}

int main() {
	read(n); read(m); read(k);
	for(register int i = 1; i <= m; i++) {
		int u, v; read(u); read(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dep[1] = 1; dfs1(1);
	int p = (n - 1) / k + 1;
	if(dep[maxn] - 1 >= p) {
		printf("PATH\n");
		print(dep[maxn], '\n');
		while(maxn) print(maxn, ' '), maxn = fa[maxn];
	} else {
		printf("CYCLES\n");
		int cnt = 0;
		for(register int i = 1; i <= n; i++) {
			if(leaf[i]) {
				int v1 = fa[i], v2 = 0, v3 = 0;
				for(register unsigned j = 0; j < adj[i].size(); j++) {
					if(adj[i][j] == v1) continue;
					if(!v2) v2 = adj[i][j];
					else if(!v3) { v3 = adj[i][j]; break; }
				}
				if(dep[v1] < dep[v2]) swap(v1, v2);
				if(dep[v1] < dep[v3]) swap(v1, v3);
				if(dep[v2] < dep[v3]) swap(v2, v3);
				if(check(i, v1, v2)) calc(i, v1, v2);
				else if(check(i, v1, v3)) calc(i, v1, v3);
				else if(check(i, v2, v3)) calc(i, v2, v3);
				++cnt; if(cnt == k) break;
			}
		}
	}
	return 0;
} // qwq