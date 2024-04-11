// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5;

int n, fa[N], sg[N], a, b;

vector<int> g[N]; 

void dfs(int u) {
	for (int v: g[u]) {
		if (v == fa[u]) continue;
		fa[v] = u;
		dfs(v);
		sg[u] ^= (sg[v] + 1);
	}
}

bool vis[N];

void inline out() {
	int ret = (a ^ b);
	putchar(ret ? '1' : '2');
}

int main() {
	read(n);
	for (int i = 1, u, v; i < n; i++)
		read(u), read(v), g[u].pb(v), g[v].pb(u);
	dfs(1);
	a = sg[1];
	vis[1] = 1;
	out();
	for (int i = 2; i <= n; i++) {
		int x = i;
		while (!vis[x]) {
			vis[x] = 1;
			for (int v: g[x]) {
				if (v == fa[x] || vis[v]) continue;
				a ^= sg[v] + 1;
			}
			if (vis[fa[x]]) a ^= sg[x] + 1;
			b ^= 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
			x = fa[x];
		}
		out();
	}
    return 0;
}