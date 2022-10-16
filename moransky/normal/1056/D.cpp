#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
int n, sz[N];
int head[N], numE = 0;
struct E{
	int next, v;
}e[N];
void add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}


void dfs(int u) {
	if(!head[u]) {
		sz[u] = 1; return;
	}
	
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		dfs(v);
		sz[u] += sz[v];
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 2, p; i <= n; i++) {
		scanf("%d", &p); add(p, i);
	}
	
	dfs(1);
	
	sort(sz + 1, sz + 1 + n);
	
	int c = 0, now = 0;
	for (int i = 1; i <= n; i++) {
		if(now < i) {
			++now;
			c = max(c, sz[now]);
		}
		while(now < n && c >= sz[now + 1]) ++now;
		printf("%d ", c);
	}
	return 0;
}