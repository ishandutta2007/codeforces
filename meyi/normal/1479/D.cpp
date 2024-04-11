#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int a[maxn],n;
int dep[maxn],fa[maxn],siz[maxn],son[maxn],st[maxn],top[maxn],tp;
int bel[maxn],cnt,m;
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	fa[p]=f;
	siz[p]=1;
	ri tmp=tp;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs1(e[i].to,p);
			siz[p]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
			if(tp-tmp>=m){
				++cnt;
				while(tp>=tmp)bel[st[tp--]]=cnt;
			}
		}
	st[++tp]=p;
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
const int maxp=550;
struct block{
	int bel[maxn],cnt,m,kl[maxp],kr[maxp],ksum[maxp];
	bool vis[maxn];
	inline void init(){
		m=max((int)sqrt(n),2);
		for(ri i=1;i<=n;++i){
			if(i%m==1)kr[cnt]=i-1,kl[++cnt]=i;
			bel[i]=cnt;
		}
		kr[cnt]=n;
	}
	inline void change(int k){
		if(vis[k])--ksum[bel[k]];
		else ++ksum[bel[k]];
		vis[k]^=1;
	}
	inline int query(int l,int r){
		ri L=bel[l],R=bel[r];
		if(L==R){
			for(ri i=l;i<=r;++i)
				if(vis[i])
					return i;
			return -1;
		}
		for(ri i=l;i<=kr[L];++i)
			if(vis[i])
				return i;
		for(ri i=L+1;i<R;++i)
			if(ksum[i])
				for(ri j=kl[i];j<=kr[i];++j)
					if(vis[j])
						return j;
		for(ri i=kl[R];i<=r;++i)
			if(vis[i])
				return i;
		return -1;
	}
}b;
inline void change_chain(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y]){
		b.change(a[x]);
		x=fa[x];
	}
	while(x!=y){
		b.change(a[x]),b.change(a[y]);
		x=fa[x],y=fa[y];
	}
}
struct qry{
	int l,L,r,R,id;
	inline bool operator<(const qry &k)const{
		return bel[l]!=bel[k.l]?bel[l]<bel[k.l]:bel[r]<bel[k.r];
	}
}q[maxn];
int ans[maxn],ql;
int main(){
	scanf("%d%d",&n,&ql);
	m=sqrt(n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs1(1,0);
	while(tp)bel[st[tp--]]=cnt;
	dfs2(1,1);
	for(ri i=1;i<=ql;++i)scanf("%d%d%d%d",&q[i].l,&q[i].r,&q[i].L,&q[i].R),q[i].id=i;
	sort(q+1,q+ql+1);
	ri pl=1,pr=1;
	b.init();
	for(ri i=1;i<=ql;++i){
		change_chain(pl,q[i].l);
		change_chain(pr,q[i].r);
		pl=q[i].l,pr=q[i].r;
		ri l=lca(pl,pr);
		b.change(a[l]);
		ans[q[i].id]=b.query(q[i].L,q[i].R);
		b.change(a[l]);
	}
	for(ri i=1;i<=ql;++i)printf("%d\n",ans[i]);
	return 0;
}