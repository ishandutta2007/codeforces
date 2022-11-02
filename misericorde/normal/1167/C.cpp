#include <bits/stdc++.h>
#define maxn 1000005
int n,t,u,cnt=0,head[maxn]={0},tail=0,vis[maxn]={0},size[maxn]={0},k;
struct edge {
	int v,next;
}edges[maxn<<1];
void add_edge(int u,int v){
	edges[++tail].v=v;
	edges[tail].next=head[u];
	head[u]=tail;
}

void bfs(int u) {
	vis[u]=++cnt;
	std::queue<int>q;q.push(u);
	while (!q.empty()) {
		int x=q.front();q.pop();
		for (int i=head[x];i;i=edges[i].next) {
			if (!vis[edges[i].v]) {vis[edges[i].v]=cnt;q.push(edges[i].v);}
		}
	}
}

int main() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;++i) {
		scanf("%d",&t);
		for (int j=1;j<=t;++j) {
			scanf("%d",&u);
			add_edge(n+i,u);add_edge(u,n+i);
		}
	} for (int i=1;i<=n;++i){
		if (!vis[i]) bfs(i);
	}for (int i=1;i<=n;++i) size[vis[i]]++;
	for (int i=1;i<=n;++i) printf("%d ",size[vis[i]]);
	return 0;
}