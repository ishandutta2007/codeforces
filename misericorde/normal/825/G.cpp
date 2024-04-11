#include <bits/stdc++.h>
#define maxn 1000005
int n,q,lastans=0,min[maxn]={0},head[maxn]={0},tail=0,u,v,t,rt=0,ans=1e9;
 
struct edge {
	int v,next;
}edges[maxn<<1];
void add_edge(int u,int v) {
	edges[++tail].v=v;
	edges[tail].next=head[u];
	head[u]=tail;
}
 
void dfs(int u,int f) {
	if (f) min[u]=std::min(u,min[f]);
	else min[u]=u;
	for (int i=head[u];i;i=edges[i].next){
		int v=edges[i].v;
		if (v==f) continue;
		dfs(v,u);
	}
}
 
int main() {
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;++i) {
		scanf("%d%d",&u,&v);
		add_edge(u,v);add_edge(v,u);
	}
	while (q--) {
		scanf("%d%d",&t,&v);v=(v+lastans)%n+1;
		if (t==1) {
			if (!rt) {dfs(v,0);rt=v;}
			ans=std::min(ans,min[v]);
		}else {
			lastans=std::min(ans,min[v]);
			printf("%d\n",lastans);
		}
	}
	return 0;
}