#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005, M = N << 1;
int n, m, K, s, fa[N];
bool st[N];
struct E{
	int u, v, w;
	bool operator < (const E &x) const {
		return w < x.w;
	}
}e[M];
int get(int x) {
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
int main(){
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	s = K;
	for (int i = 1, x; i <= K; i++)
		scanf("%d", &x), st[x] = true; 
	
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	}
	sort(e + 1, e + 1 + m);
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		u = get(u), v = get(v);
		if(u != v) {
			fa[u] = v;
			 
			if(st[u] && st[v]) {
				s--;
				
			}
			st[u] |= st[v];
			st[v] |= st[u];
		}
		if(s == 1) {
			for (int j = 1; j <= K; j++)
				printf("%d ", e[i].w);
			break;
		} 
	}
	return 0;
}