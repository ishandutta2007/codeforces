#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 100005, M = N << 1;
int n, m;
int head[N], numE = 0;
bool vis[N];
struct Edge{
	int next, v;
}e[M];
void add(int u, int v) {
	e[++numE] = (Edge) { head[u], v };
	head[u] = numE;
} 
priority_queue<int, vector<int>, greater<int> > q;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	
	q.push(1); vis[1] = true;
	while(!q.empty()) {
		int u = q.top(); q.pop();
		printf("%d ", u);
		for (int i = head[u]; i; i = e[i].next) {
			int v = e[i].v;
			if(!vis[v]) {
				vis[v] = true;
				q.push(v);
			}
		}
	}
	return 0;
}