#include<cstdio>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

#define int long long
int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=5e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m;
ll a[4][N];
struct Query {
	int l,r,k;
} q[N];
ll f[N],g[N],dp[N];
const int NN=1<<19;
struct ST {
	ll seg[NN<<1];
	void change(int p,ll v) {
		for(p+=NN;p!=1;p>>=1) seg[p]=max(seg[p],v);
	}
	ll query(int l,int r) {
		ll z=-INF;
		for(l+=NN-1,r+=NN+1;l^r^1;l>>=1,r>>=1) {
			if(~l&1) z=max(z,seg[l^1]);
			if(r&1) z=max(z,seg[r^1]);
		} return z;
	}
} T1,T2;
ll seg[N<<2],sg[N<<2],sr[N<<2];
void pushup(int k,int lc,int rc) {
	seg[k]=max({seg[lc],seg[rc],sg[lc]+sr[rc]});
	sg[k]=max(sg[lc],sg[rc]);
	sr[k]=max(sr[lc],sr[rc]);
}
#define lc (k<<1)
#define rc (lc|1)
void build(int k,int l,int r) {
	if(l==r) {
		seg[k]=-INF;
		sg[k]=g[l];
		sr[k]=-INF;
		return;
	}
	int mid=l+r>>1;
	build(lc,l,mid),build(rc,mid+1,r);
	pushup(k,lc,rc);
}
void change2(int k,int l,int r,int p,ll v) {
	if(l==r) {
		sr[k]=max(sr[k],v);
		seg[k]=sg[k]+sr[k];
		return;
	}
	int mid=l+r>>1;
	if(p<=mid) change2(lc,l,mid,p,v);
	else change2(rc,mid+1,r,p,v);
	pushup(k,lc,rc);
}
void _query2(int k,int l,int r,int x) {
	if(x<=l) return pushup(0,0,k);
	int mid=l+r>>1;
	if(x<=mid) _query2(lc,l,mid,x);
	_query2(rc,mid+1,r,x);
}
ll query2(int k,int l,int r,int x) {
	seg[0]=sg[0]=sr[0]=-INF;
	_query2(k,l,r,x); return seg[0];
}
vector<int> buc[N];
signed main() {
	n=read(); m=read();
	fr(k,1,3) fr(i,1,n) a[k][i]=read()+a[k][i-1];
	fr(i,1,n) {
		f[i]=a[1][i]-a[2][i-1];
		g[i]=a[3][n]-a[3][i-1]-(a[2][n]-a[2][i]);
	}
	fr(i,1,m) q[i].l=read(),q[i].r=read(),q[i].k=read();
	sort(q+1,q+m+1,[](const Query &a,const Query &b) {
		return a.r<b.r;
	});
	fr(i,1,m) buc[q[i].l].push_back(i);
	ll ans=-0x3f3f3f3f3f3f3f3f;
	memset(&T1,-0x3f,sizeof T1);
	memset(&T2,-0x3f,sizeof T2);
	fr(i,1,n) T1.change(i,f[i]);
	build(1,1,n);
	int pt=1;
	fr(i,1,m) {
		dp[i]=T1.query(q[i].l,q[i].r)-q[i].k;
		dp[i]=max(dp[i],T2.query(max(q[i].l-1,1ll),q[i].r)-q[i].k);
		for(;pt<=n&&pt<=q[i].r+1;++pt)
			for(auto x:buc[pt]) change2(1,1,n,q[x].r,-q[x].k);
		ans=max(ans,dp[i]+query2(1,1,n,q[i].r));
		T2.change(q[i].r,dp[i]);
	}
	build(1,1,n);
	fr(i,1,n) {
		for(auto x:buc[i]) change2(1,1,n,q[x].r,-q[x].k);
		ans=max(ans,f[i]+query2(1,1,n,i));
	}
	cout<<ans+a[2][n]<<endl;
	return 0;
}

inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}