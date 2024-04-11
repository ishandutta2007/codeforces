#include<cstdio>
#include<cassert>
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

const int N=5e5+5;
int n;
int fir[N],to[N<<1],eds,nxt[N<<1];
void addedge(int u,int v) {
	to[++eds]=v;
	nxt[eds]=fir[u];
	fir[u]=eds;
}
struct Line {
	ll k,b;
	ll operator () (const ll &x) {return k*x+b;}
};
Line seg[N<<2]; int tag[N<<2];
#define lc (k<<1)
#define rc (lc|1)
#define left lc,l,mid
#define right rc,mid+1,r
void change(int k,int l,int r,Line v) {
	int mid=l+r>>1;
	if(!tag[k]) return tag[k]=1,seg[k]=v,void();
	if(v(mid)<seg[k](mid)) swap(seg[k],v);
	if(l==r) return;
	if(v.k<seg[k].k) change(right,v);
	else change(left,v);
}
ll query(int k,int l,int r,ll x) {
	if(!tag[k]) return 4e18;
	if(l==r) return seg[k](x);
	int mid=l+r>>1;
	return min(seg[k](x),x<=mid?query(left,x):query(right,x));
}
void clear(int k,int l,int r) {
	if(!tag[k]) return;
	tag[k]=0; if(l==r) return;
	int mid=l+r>>1;
	clear(left); clear(right);
}
ll dp[N],ans=4e18,siz[N];
void dfs(int u,int fa) {
	siz[u]=1;
	foredge(i,u,v) if(v!=fa)
		dfs(v,u),siz[u]+=siz[v];
	dp[u]=4e18;
	clear(1,1,n);
	foredge(i,u,v) if(v!=fa) {
		dp[u]=min(dp[u],dp[v]+(siz[u]-siz[v])*(siz[u]-siz[v]));
		ans=min(ans,dp[v]+(n-siz[v])*(n-siz[v]));
		ans=min(ans,query(1,1,n,siz[v])+siz[v]*siz[v]+dp[v]);
		change(1,1,n,(Line){-2*(n-siz[v]),dp[v]+(n-siz[v])*(n-siz[v])});
	}
	if(dp[u]>2e18) dp[u]=1;
}
int main() {
	n=read();
	for(int i=1,u,v;i<n;++i) {
		u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,0);
	printf("%lld\n",1ll*n*n-(ans+n>>1));
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}