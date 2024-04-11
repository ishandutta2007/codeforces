#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=105,M=1e5+5;
int n,m,q;
ll a[N],b[M];
ll seg[M<<2],sum[M<<2],tag[M<<2],mx[M<<2];
#define lc (k<<1)
#define rc (lc|1)
#define left lc,l,mid
#define right rc,mid+1,r
void pushup(int k) {
	seg[k]=seg[lc]+seg[rc];
	sum[k]=sum[lc]+sum[rc];
	mx[k]=mx[rc];
}
ll getsum(ll l,ll r) {return (l+r)*(r-l+1)/2;}
void puttag(int k,int l,int r,ll v) {
	seg[k]+=getsum(m-r+1,m-l+1)*v;
	sum[k]+=(r-l+1)*v;
	mx[k]+=v;
	tag[k]+=v;
}
void pushdown(int k,int l,int r,int mid) {
	if(tag[k]) {
		puttag(left,tag[k]);
		puttag(right,tag[k]);
		tag[k]=0;
	}
}
void build(int k,int l,int r) {
	if(l==r) {
		seg[k]=(m-l+1)*b[l];
		mx[k]=sum[k]=b[l]; return;
	}
	int mid=l+r>>1;
	build(left); build(right); pushup(k);
}
void change(int k,int l,int r,int x,int y,ll v) {
	if(x<=l&&r<=y) return puttag(k,l,r,v);
	int mid=l+r>>1; pushdown(k,l,r,mid);
	if(x<=mid) change(left,x,y,v);
	if(y>mid) change(right,x,y,v);
	pushup(k);
}
ll query(int k,int l,int r,int x,int y) {
	if(x<=l&&r<=y) return sum[k];
	int mid=l+r>>1; pushdown(k,l,r,mid);
	ll res=0;
	if(x<=mid) res=query(left,x,y);
	if(y>mid) res+=query(right,x,y);
	return res;
}
int search(int k,int l,int r,ll v) {
	int mid=l+r>>1,res=-1;
	if(l!=r) pushdown(k,l,r,mid);
	if(mx[k]<v) return -1;
	if(l==r) return l;
	return mx[lc]>=v?search(left,v):search(right,v);
}
int main() {
	scanf("%d%d%d",&n,&m,&q);
	fr(i,1,n) scanf("%lld",a+i);
	fr(i,1,m) scanf("%lld",b+i);
	rf(i,m,1) b[i]=b[i]-b[i-1];
	build(1,2,m);
	while(q--) {
		static int op,k,d;
		scanf("%d%d%d",&op,&k,&d);
		if(op==1) fr(i,n-k+1,n) a[i]+=1ll*d*(i-n+k);
		else {
			change(1,2,m,m-k+1+(k==m),m,d);
			if(k==m) b[1]+=d;
		}
		ll ans=(a[1]+b[1])*(n+m-1)+seg[1];
		fr(i,2,n) {
			int p=search(1,2,m,a[i]-a[i-1])-1;
			if(p<0) p=m;
			if(p>=2) ans+=query(1,2,m,2,p);
			ans+=(a[i]-a[i-1])*(n-i+1+m-p);
		}
		printf("%lld\n",ans);
	}
	return 0;
}