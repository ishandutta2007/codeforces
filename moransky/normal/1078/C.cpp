#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 300005, P = 998244353;

int n, f[N][3];

vector<int> g[N];

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

void dfs(int u, int fa) {
	f[u][0] = f[u][2] = 1;
	for (int o = 0; o < g[u].size(); o++) {
		int v = g[u][o];
		if (v == fa) continue;
		dfs(v, u);
		int w[3] = { 0, 0, 0 };
		add(w[0], (LL)f[u][0] * (f[v][1] + f[v][2]) % P);
		add(w[1], (LL)f[u][1] * (f[v][1] + f[v][2]) % P);
		
		add(w[1], (LL)f[u][0] * (f[v][0] + f[v][2]) % P);
		add(w[0], (LL)f[u][0] * f[v][1] % P);
		add(w[1], (LL)f[u][1] * f[v][1] % P);
		add(w[2], (LL)f[u][2] * (f[v][1] + f[v][2]) % P);
		for (int i = 0; i < 3; i++)
			f[u][i] = w[i];
	}
	f[u][0] = (f[u][0] - f[u][2] + P) % P; 
}

int main() {
    read(n);
    for (int i = 1, u, v; i < n; i++) 
    	read(u), read(v), g[u].pb(v), g[v].pb(u);
    dfs(1, 0);
    int ans = (f[1][1] + f[1][2]) % P;
    print(ans);
}