#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, m, nxt[N], pre[N], ans[N], tot = 0;
set<int> g[N];
bool vis[N];
queue<int> q;
void inline del(int x) {
	pre[nxt[x]] = pre[x];
	nxt[pre[x]] = nxt[x];
}
void bfs(int s) {
	del(s); 
	while(!q.empty()) q.pop();
	int cnt = 1; q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = nxt[0]; i; i = nxt[i]) {
			if(g[u].count(i) > 0 || vis[i]) continue;
			cnt++, vis[i] = true, q.push(i); del(i);
		}
	}
	ans[++tot] = cnt;
} 
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d", &u, &v);
		g[u].insert(v); g[v].insert(u); 
	}
	
	for (int i = 1; i <= n; i++) {
		nxt[i] = i + 1;
		pre[i] = i - 1;
	}
	nxt[n] = 0;
	nxt[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = true;
			bfs(i); 
		}
	}
	sort(ans + 1, ans + 1 + tot);
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++)
		printf("%d ", ans[i]);
	return 0;
}