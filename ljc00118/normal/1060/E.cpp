#include <bits/stdc++.h>
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

const int N = 2e5 + 5;

struct Edge {
	int u, v, next;
}G[N << 1];

ll ans;
int siz[N], fa[N], head[N];
int n, tot;

inline void addedge(int u, int v) {
	G[++tot] = (Edge) {u, v, head[u]}, head[u] = tot;
	G[++tot] = (Edge) {v, u, head[v]}, head[v] = tot;
}

ll f[2];

void dfs(int u, int now) {
	siz[u] = 1; f[now]++;
	for(int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if(v == fa[u]) continue;
		fa[v] = u; dfs(v, now ^ 1);
		siz[u] += siz[v]; 
	}
	ans += (ll)siz[u] * (ll)(n - siz[u]);
}

int main() {
	cin >> n;
	for(int i = 1; i < n; i++) {
		int a, b;
		read(a); read(b);
		addedge(a, b); 
	}
	dfs(1, 0);
	cout << (ans + f[0] * f[1]) / 2ll << endl;
	return 0;
}