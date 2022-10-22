#include<bits/stdc++.h>
using namespace std;
#define ri int
const int maxn=2e5+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int deg[maxn],hd[maxn],len;
inline void addedge(int fr,int to){
	++deg[to];
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
struct dsu{
	int fa[maxn],siz[maxn];
	inline void init(int k){
		for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;
	}
	int find(int k){
		return k==fa[k]?k:fa[k]=find(fa[k]);
	}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y,siz[y]+=siz[x];
		}
	}
}d;
int ans[maxn],cnt,m,n;
bool vis[maxn];
signed main(){
	#ifndef ONLINE_JUDGE
		freopen("CF920E.in","r",stdin);
		freopen("CF920E.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	ri pos=0;
	deg[pos]=INT_MAX;
	for(ri i=1;i<=n;++i)
		if(deg[i]<deg[pos])
			pos=i;
	d.init(n);
	vis[pos]=true;
	for(ri i=hd[pos];i;i=e[i].nxt)vis[e[i].to]=true;
	for(ri i=1;i<=n;++i)
		if(!vis[i])
			d.merge(i,pos);
	for(ri i=hd[pos];i;i=e[i].nxt){
		ri p=e[i].to;
		memset(vis,0,sizeof vis);
		for(ri j=hd[p];j;j=e[j].nxt)vis[e[j].to]=true;
		for(ri j=1;j<=n;++j)
			if(!vis[j])
				d.merge(j,p);
	}
	for(ri i=1;i<=n;++i)
		if(d.find(i)==i)
			ans[++cnt]=d.siz[i];
	printf("%d\n",cnt);
	sort(ans+1,ans+cnt+1);
	for(ri i=1;i<=cnt;++i)printf("%d ",ans[i]);
	return 0;
}