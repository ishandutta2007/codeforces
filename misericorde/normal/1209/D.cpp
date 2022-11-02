#include <bits/stdc++.h>
#define maxn 200005
struct edge {
	int v,next;
}edges[maxn<<1];
int head[maxn]={0},degr[maxn]={0},n,k,cnt=0,vis[maxn]={0},tail=0;
void add_edge(int u,int v){
	edges[++tail].v=v;
	edges[tail].next=head[u];
	head[u]=tail;
}

int dfs(int u){
	vis[u]=1;
	int ans=1;
	for (int i=head[u];i;i=edges[i].next){
		int v=edges[i].v;
		if (!vis[v])ans+=dfs(v);
	}return ans;
}

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);add_edge(v,u);
		degr[u]++;degr[v]++;
	}
	for (int i=1;i<=n;++i){
		if (!vis[i]){cnt+=dfs(i)-1;}
	}
	printf("%d",k-cnt);
	return 0;
}