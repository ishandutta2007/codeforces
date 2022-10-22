#include <bits/stdc++.h>
#define f(i, j) f[i][j + R + 1]
#define g(i) tmp[i + R + 1]
using namespace std;
const int N = 310, P = 998244353, inv = (P + 1) / 2;
int n, R;
vector<int> g[N];
int f[N][N << 1], tmp[N << 1];

void adde(int u, int v) {g[u].push_back(v); }
void Add(int &x, int y) { 
	if((x += y) >= P && (x -= P));
}

void Merge(int u, int v) {
	for(int i = - R - 1; i <= R; i++) g(i) = 0;
	for(int i = -R - 1; i <= R; i++) {
		if(!f(u, i)) continue;
		for(int j = - R - 1; j < R; j++) {
			if(i + j + 1 < 0) {
				Add(g(min(i, j + 1)), 1ll * f(u, i) * f(v, j) % P);
			} else {
				Add(g(max(i, j + 1)), 1ll * f(u, i) * f(v, j) % P);
			}
		}
	}
	for(int i = -R - 1; i <= R; i++) f(u, i) = g(i);
	return;
}

void DFS(int u, int fa) {
	for(int i = -R - 1; i <= R; i++) f(u, i) = 0;
	f(u, 0) = f(u, - R - 1) = inv;
	for(int &v : g[u]) {
		if(v == fa) continue;
		DFS(v, u);
		Merge(u, v);
	}
	return;
}

int Calc(int r) {
	R = r;
	DFS(1, 0);
	int res = 0;
	for(int i = -R - 1; i < 0; i++) res = (res + f(1, i)) % P;
	return res;
}

int main() {
	scanf("%d", &n);
	for(int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		adde(u, v), adde(v, u);
	}
	int ans = n;
	for(int i = n; i >= 0; i--) ans = (ans - Calc(i) + P) % P;
	printf("%d\n", ans);
	return 0;
}