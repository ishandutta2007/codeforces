#include <bits/stdc++.h>
#define int long long
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

const int N = 1e5 + 5;

struct Edge {
	int u, v, next;
}G[N];

int f[N][20], g[N][20];
int head[N], w[N], Up[N];
int n, L, s, tot, Ans;

inline void addedge(int u, int v) {
	G[++tot] = (Edge) {u, v, head[u]}, head[u] = tot;
}

int dfs(int u) {
	int Max = 0;
	for(register int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		Max = max(Max, dfs(v));
	}
	if(!Max) {
		Ans++;
		Max = Up[u];
	}
	return Max - 1;
}

#undef int
int main() {
#define int long long
	read(n); read(L); read(s);
	for(register int i = 1; i <= n; i++) {
		read(w[i]);
		if(w[i] > s) {
			cout << -1 << endl;
			return 0;
		}
	}
	for(register int i = 2; i <= n; i++) {
		int a; read(a);
		addedge(a, i);
		f[i][0] = a; g[i][0] = w[a];
	}
	for(register int j = 1; j <= 17; j++) {
		for(register int i = 1; i <= n; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
			g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1];
		}
	}
	for(register int i = 1; i <= n; i++) {
		register int u = i, now = w[i], ans = 1;
		for(register int j = 17; j >= 0; j--) {
			if(f[u][j] && (ans + (1 << j)) <= L && (now + g[u][j]) <= s) {
				ans += (1 << j);
				now += g[u][j];
				u = f[u][j];
			}
		}
		Up[i] = ans;
	}
	dfs(1); cout << Ans << endl;
	return 0;
}