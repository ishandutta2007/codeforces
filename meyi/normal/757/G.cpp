#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int b=(1<<30)-1,lim=31597024,maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
ll dep[maxn],pre[maxn];
int dfn,fa[maxn],seg[maxn],siz[maxn],son[maxn],top[maxn],val[maxn];
void dfs1(int p,int f){
	fa[p]=f;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dep[e[i].to]=dep[p]+e[i].v;
			val[e[i].to]=e[i].v;
			dfs1(e[i].to,p);
			siz[p]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
		}
}
void dfs2(int p,int k){
	seg[p]=++dfn;
	pre[dfn]=pre[dfn-1]+val[p];
	top[p]=k;
	if(son[p]){
		dfs2(son[p],k);
		for(ri i=hd[p];i;i=e[i].nxt)
			if(!top[e[i].to])
				dfs2(e[i].to,e[i].to);
	}
}
struct segment_tree{
	int ls,rs,tag;
	ll sum;
}t[maxn*160];
int cnt;
int insert(int p,int l,int r,int ql,int qr,int lst){
	if(p==lst){
		t[++cnt]=t[p];
		p=cnt;
	}
	if(ql<=l&&r<=qr){
		++t[p].tag;
		return p;
	}
	t[p].sum+=pre[qr]-pre[ql-1];
	if(l==r)return p;
	ri mid=l+r>>1;
	if(ql<=mid)t[p].ls=insert(t[p].ls,l,mid,ql,min(mid,qr),t[lst].ls);
	if(qr>mid)t[p].rs=insert(t[p].rs,mid+1,r,max(ql,mid+1),qr,t[lst].rs);
	return p;
}
ll query(int p,int l,int r,int ql,int qr){
	ll ret=(pre[qr]-pre[ql-1])*t[p].tag;
	if(ql<=l&&r<=qr)return ret+t[p].sum;
	ri mid=l+r>>1;
	if(ql<=mid)ret+=query(t[p].ls,l,mid,ql,min(mid,qr));
	if(qr>mid)ret+=query(t[p].rs,mid+1,r,max(ql,mid+1),qr);
	return ret;
}
int a[maxn],n,rt[maxn];
ll sum[maxn];
inline void modify(int x){
	rt[x]=rt[x-1];
	sum[x]=sum[x-1]+dep[a[x]];
	for(ri p=a[x];p;p=fa[top[p]])rt[x]=insert(rt[x],1,n,seg[top[p]],seg[p],rt[x-1]);
}
inline ll query(int k,int x){
	ll ret=0;
	for(ri p=x;p;p=fa[top[p]])ret+=query(rt[k],1,n,seg[top[p]],seg[p]);
	return ret;
}
int lst,q;
int main(){
	scanf("%d%d",&n,&q);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1,x,y,z;i<n;++i){
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z),addedge(y,x,z);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(ri i=1;i<=n;++i)modify(i);
	while(q--){
		ri op,x,y,z;
		scanf("%d%d",&op,&x);
		x^=lst;
		if(op&1){
			scanf("%d%d",&y,&z);
			y^=lst,z^=lst;
			ll tmp=(y-x+1)*dep[z]+sum[y]-sum[x-1]-2*(query(y,z)-query(x-1,z));
			printf("%lld\n",tmp);
			lst=tmp&b;
		}
		else{
			swap(a[x],a[x+1]);
			if(cnt<lim)modify(x);
			else{
				cnt=0;
				for(ri i=1;i<=n;++i)modify(i);
			}
		}
	}
	return 0;
}