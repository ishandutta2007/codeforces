#include<bits/stdc++.h>
using namespace std;
#define ri register int
const int maxn=3e5+10;
struct edge{
	int to,nxt,son;
}e[maxn<<1];
int c[maxn],cnt,dep[maxn],fa[maxn],hd[maxn],len,m,n,rev[maxn],seg[maxn],siz[maxn],son[maxn],top[maxn];
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
inline int lowbit(int k){return k&-k;}
inline void add(int k,int v){
	while(k<=n)c[k]+=v,k+=lowbit(k);
}
inline int query(int k){
	int ret=0;
	while(k)ret+=c[k],k-=lowbit(k);
	return ret;
}
inline int query(int l,int r){
	if(l>r)return 0;
	return query(r)-query(l-1);
}
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	fa[p]=f;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs1(e[i].to,p);
			e[i].son=e[((i-1)^1)+1].son=e[i].to;
			siz[p]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
		}
}
void dfs2(int p,int k){
	seg[p]=++cnt;
	rev[cnt]=p;
	top[p]=k;
	if(son[p])dfs2(son[p],k);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!top[e[i].to])
			dfs2(e[i].to,e[i].to);
}
inline int query_chain(int x,int y){
	int ret=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		if(query(seg[top[x]],seg[x]))return -1;
		ret+=dep[x]-dep[top[x]]+1;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(x==y)return ret;
	return query(seg[son[x]],seg[y])?-1:ret+dep[y]-dep[x];
}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	scanf("%d",&m);
	while(m--){
		int op,x,y;
		scanf("%d%d",&op,&x);
		switch(op){
			case 1:{
				add(seg[e[x<<1].son],-query(seg[e[x<<1].son],seg[e[x<<1].son]));
				break;
			}
			case 2:{
				add(seg[e[x<<1].son],1-query(seg[e[x<<1].son],seg[e[x<<1].son]));
				break;
			}
			case 3:{
				scanf("%d",&y);
				printf("%d\n",query_chain(x,y));
				break;
			}
		}
	}
	return 0;
}