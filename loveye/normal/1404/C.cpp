#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=3e5+5,INF=0x7fffffff;
int n,m,ans[N];
struct Query {
	int l,r,id;
} q[N];
int a[N],f[N];
int seg[N<<2],tag[N<<2];
#define lc (k<<1)
#define rc (lc|1)
#define left lc,l,mid
#define right rc,mid+1,r
void pushup(int k) {seg[k]=min(seg[lc],seg[rc]);}
void puttag(int k,int v) {seg[k]+=v; tag[k]+=v;}
void pushdown(int k) {if(tag[k]) puttag(lc,tag[k]),puttag(rc,tag[k]),tag[k]=0;}
void activate(int k,int l,int r,int pos) {
	if(l==r) {
		if(a[l]<0) seg[k]=INF;
		else seg[k]=a[l];
		return;
	}
	int mid=l+r>>1; pushdown(k);
	if(pos<=mid) activate(left,pos);
	else activate(right,pos);
	pushup(k);
}
void change(int k,int l,int r,int pos) {
	if(pos<=l) return puttag(k,-1);
	int mid=l+r>>1; pushdown(k);
	if(pos<=mid) change(left,pos);
	change(right,pos);
	pushup(k);
}
int work(int k,int l,int r,int pos) {
	if(l!=r) pushdown(k);
	int mid=l+r>>1;
	if(pos<=l) {
		if(seg[k]>0) return 0;
		if(l==r) {
			f[l]=pos;
			seg[k]=INF;
			if(l<n) change(1,1,n,l+1);
			return 1;
		}
		int ret=seg[k]==seg[lc]?work(left,pos):work(right,pos);
		pushup(k); return ret;
	}
	if(pos<=mid&&work(left,pos)) return pushup(k),1;
	int ret=work(right,pos); return pushup(k),ret;
}
int BIT[N]; void add(int x,int v) {for(;x<=n;x+=x&-x) BIT[x]+=v;}
int ask(int x) {int z=0; for(;x;x&=x-1) z+=BIT[x]; return z;}
int main() {
	scanf("%d%d",&n,&m);
	fr(i,1,n) scanf("%d",a+i),a[i]=i-a[i];
	rf(i,n,1) {
		activate(1,1,n,i);
		while(work(1,1,n,i));
	}
	fr(i,1,m) {
		scanf("%d%d",&q[i].l,&q[i].r);
		++q[i].l; q[i].r=n-q[i].r;
		q[i].id=i;
	}
	sort(q+1,q+m+1,[](const Query &a,const Query &b) {
		return a.r<b.r;
	});
	int pt=1;
	fr(i,1,m) {
		for(;pt<=q[i].r;++pt) if(f[pt]) add(f[pt],1);
		ans[q[i].id]=ask(n)-ask(q[i].l-1);
	}
	fr(i,1,m) printf("%d\n",ans[i]);
	return 0;
}