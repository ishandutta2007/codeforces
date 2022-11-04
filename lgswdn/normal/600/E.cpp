#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;

struct edge {int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;}

int n,c[N],sz[N],son[N];
void dfs1(int u,int fa) {
	sz[u]=1;
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if((v=e[i].to)==fa) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}

int cnt[N],mx[N]; long long sum[N]; 
void copy(int u,int v) {sum[u]=sum[v],mx[u]=mx[v];}
void cal(int x,int u,int fa) {
	cnt[c[u]]++;
	if(cnt[c[u]]>mx[x]) mx[x]=cnt[c[u]], sum[x]=c[u];
	else if(cnt[c[u]]==mx[x]) sum[x]+=c[u];
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if((v=e[i].to)==fa||v==son[x]) continue;
		cal(x,v,u);
	}
}
void clear(int u,int fa) {
	cnt[c[u]]--;
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if((v=e[i].to)==fa) continue;
		clear(v,u);
	}
}
void dfs2(int u,int fa) {
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if((v=e[i].to)==fa||v==son[u]) continue;
		dfs2(v,u), clear(v,u);
	}
	if(son[u]) dfs2(son[u],u);
	copy(u,son[u]),cal(u,u,fa);
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v), add(u,v), add(v,u);
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++) printf("%lld ",sum[i]);
	return 0;
}