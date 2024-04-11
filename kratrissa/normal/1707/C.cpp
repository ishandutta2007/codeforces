#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,m,q,a[N],p[N],hd[N],nxt[N<<1],to[N<<1],tot,id[N],top[N],fa[N],sz[N],dep[N],cnt,d[N],rk[N];pair<int,int> e[N];
int fnd(int x){return p[x]==x?x:p[x]=fnd(p[x]);}
void add(int x,int y){to[++tot]=y,nxt[tot]=hd[x],hd[x]=tot;}
void dfs(int x,int Fa){
	sz[x]=1,fa[x]=Fa,dep[x]=dep[Fa]+1;
	for(int i=hd[x],y;i;i=nxt[i])
		if((y=to[i])!=Fa)dfs(y,x),sz[x]+=sz[y];
}
void dfs2(int x,int tp){
	top[x]=tp,rk[id[x]=++cnt]=x;
	int hson=0;
	for(int i=hd[x],y;i;i=nxt[i])
		if((y=to[i])!=fa[x]&&sz[y]>sz[hson])hson=y;
	if(hson)dfs2(hson,tp);
	for(int i=hd[x],y;i;i=nxt[i])
		if((y=to[i])!=fa[x]&&y!=hson)dfs2(y,y);
}
int lca(int x,int y){
	for(;top[x]!=top[y];y=fa[top[y]])
		if(dep[top[x]]>dep[top[y]])swap(x,y);
	return dep[x]<dep[y]?x:y;
}
int getd(int x,int y){
	for(;top[x]!=top[y];x=fa[top[x]])
		if(fa[top[x]]==y)return top[x];
	return rk[id[y]+1];
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		if(fnd(u)==fnd(v))e[++q]=make_pair(u,v);
		else p[fnd(u)]=fnd(v),add(u,v),add(v,u);
	}
	dfs(1,0),dfs2(1,1);
	for(int i=1;i<=q;i++){
		int u=e[i].first,v=e[i].second,p=lca(u,v);
		if(p!=u&&p!=v){d[id[u]]++,d[id[u]+sz[u]]--,d[id[v]]++,d[id[v]+sz[v]]--;continue;}
		if(p==u)swap(u,v);
		int t=getd(u,p);
		d[1]++,d[id[t]]--,d[id[t]+sz[t]]++,d[id[u]]++,d[id[u]+sz[u]]--;
	}
	for(int i=1;i<=n;i++)d[i]+=d[i-1];
	for(int i=1;i<=n;i++)putchar('0'+(d[id[i]]==q));putchar('\n');
}
int main(){
	T=1;
	while(T--)solve();
	return 0;
}