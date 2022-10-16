#include <cstdio>
#include <iostream>
#include <queue> 
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
const int N = 100005, M = 600005, S = N;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, m, K, cnt[N];
int head[N], numE = 0;
LL dis[N];
bool vis[N];
priority_queue<PLI, vector<PLI>, greater<PLI> > q;
struct E{
	int next, v, w;
}e[M];
void add(int u, int v, int w) {
	e[++numE] = (E) { head[u], v, w };
	head[u] = numE;
}
int main(){
	memset(dis, 0x3f, sizeof dis); 
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w); add(v, u, w);
	} 
	dis[1] = 0; q.push(make_pair(0, 1));
	for (int i = 1; i <= K; i++) {
		int s, x; scanf("%d%d", &s, &x);
		if(dis[s] > x) {
			dis[s] = x;
			cnt[s] = 1;
		}
	}
	
	for (int i = 2; i <= n; i++) {
		if(dis[i] != INF) q.push(make_pair(dis[i], i));
	}
	while(!q.empty()) {
		PLI u = q.top(); q.pop();
		if(vis[u.second]) continue;
		vis[u.second] = true;
		for (int i = head[u.second]; i; i = e[i].next) {
			int v = e[i].v;
			if(dis[u.second] + e[i].w <= dis[v]){
				dis[v] = dis[u.second] + e[i].w;
				cnt[v] = 0;
				q.push(make_pair(dis[v], v));
			}
		}
	}
	int ans = 0;
	for  (int i = 1; i <= n; i++) 
		if(cnt[i]) ans++;
	printf("%d\n", K - ans); 
	return 0;
}