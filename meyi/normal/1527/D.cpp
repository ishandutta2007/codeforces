#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
struct node{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int dep[maxn],fa[maxn],n,son[maxn],t,top[maxn];
ll siz[maxn];
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	fa[p]=f;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs1(e[i].to,p);
			siz[p]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
		}
}
void dfs2(int p,int k){
	top[p]=k;
	if(son[p]){
		dfs2(son[p],k);
		for(ri i=hd[p];i;i=e[i].nxt)
			if(!top[e[i].to])
				dfs2(e[i].to,e[i].to);
	}
}
inline int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
ll ans[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		len=0;
		memset(hd,0,sizeof hd);
		memset(son,0,sizeof son);
		memset(top,0,sizeof top);
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y),++x,++y;
			addedge(x,y),addedge(y,x);
		}
		dfs1(1,0);
		dfs2(1,1);
		memset(ans,0,sizeof ans);
		ll sum=1;
		for(ri i=hd[1];i;i=e[i].nxt)ans[1]+=siz[e[i].to]*sum,sum+=siz[e[i].to];
		printf("%lld",1ll*n*(n-1)/2-ans[1]);
		ri l=1,r=1,sl,sr;
		for(ri i=2;i<=n;++i){
			ri a=lca(i,l),b=lca(i,r);
			if(a==l&&b==1){
				if(l==1){
					sl=siz[i];
					for(ri j=i;fa[j]>1;j=fa[j],sl=siz[j]);
				}
				l=i;
			}
			else if(b==r&&a==1){
				if(r==1){
					sr=siz[i];
					for(ri j=i;fa[j]>1;j=fa[j],sr=siz[j]);
				}
				r=i;
			}
			else if(a!=i&&b!=i)break;
			if(l==1)ans[i]=siz[r]*(n-sr);
			else if(r==1)ans[i]=siz[l]*(n-sl);
			else ans[i]=siz[l]*siz[r];
		}
		for(ri i=2;i<=n+1;++i)printf(" %lld",ans[i-1]-ans[i]);
		printf("\n");
	}
	return 0;
}