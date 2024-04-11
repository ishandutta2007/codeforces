#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
const ll inf=1ll<<60;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head
 
const int N=201000;
int q[N],hs[N],hv[N],dep[N],id[N],l[N],r[N],bel[N],s[N],f[N],pos[N],vl[N];
int n,m,Q,tot,u,v,k,ty;
VI e[N],vec[N],ret;
pair<ll,PII> ind[N],z;
struct node {
	ll fg;
	pair<ll,PII> s;
}nd[4*N];
void upd(int p) {
	nd[p].s=min(nd[p+p].s,nd[p+p+1].s);
}
void setf(int p,ll v) {
	nd[p].fg+=v; nd[p].s.fi+=v;
}
void build(int p,int l,int r) {
	nd[p].fg=0;
	if (l==r) {
		nd[p].s=ind[l];
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
}
void push(int p) {
	if (nd[p].fg) {
		setf(p+p,nd[p].fg);
		setf(p+p+1,nd[p].fg);
		nd[p].fg=0;
	}
}
pair<ll,PII> query(int p,int l,int r,int tl,int tr) {
	if (tl==l&&tr==r) return nd[p].s;
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return min(query(p+p,l,md,tl,md),query(p+p+1,md+1,r,md+1,tr));
	}
}
void modify(int p,int l,int r,int tl,int tr,ll v) {
	if (tl>tr) return;
	if (tl==l&&tr==r) return setf(p,v);
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,v);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,v);
		else modify(p+p,l,md,tl,md,v),modify(p+p+1,md+1,r,md+1,tr,v);
		upd(p);
	}
}
 
void dfs(int u,int f) {
	id[l[u]=++tot]=u; ind[tot]=mp(inf,mp(0,0));
	for (auto v:vec[u]) {
		ind[++tot]=mp(v,mp(u,v));
		pos[v]=tot;
	}
	vl[u]=tot;
	dep[u]=dep[f]+1;
	if (hv[u]) dfs(hv[u],u);
	rep(j,0,SZ(e[u])) if (e[u][j]!=f&&e[u][j]!=hv[u])
		dfs(e[u][j],u);
	r[u]=tot;
}
void HLDoT(int rt) {
	int t=1;
	q[0]=rt;
	rep(i,0,n) {
		int u=q[i];
		rep(j,0,SZ(e[u])) if (e[u][j]!=f[u])
			f[e[u][j]]=u,dep[q[t++]=e[u][j]]=dep[u]+1;
	}
	per(i,0,n) {
		int u=q[i],p=f[u];
		s[u]++,s[p]+=s[u];
		if (!l[u]) l[u]=1;
		if (hs[p]<s[u]) hs[p]=s[u],hv[p]=u,l[p]=l[u]+1;
	}
	rep(i,0,n) {
		int u=q[i];
		if (!bel[u]) bel[u]=u;
		if (hv[u]) bel[hv[u]]=bel[u];
	}
	dfs(rt,0);
}
void query(int u,int v) {
	while (1) {
		if (bel[u]==bel[v]) {
			if (dep[u]<dep[v]) swap(u,v);
			z=min(z,query(1,1,m,l[v],vl[u]));
			break;
		} else {
			if (dep[bel[u]]<dep[bel[v]]) swap(u,v);
			z=min(z,query(1,1,m,l[bel[u]],vl[u]));
			u=f[bel[u]];
		}
	}
}
 
int main() {
	scanf("%d%d%d",&n,&m,&Q);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	rep(i,0,m) {
		scanf("%d",&u);
		vec[u].pb(i+1);
	}
	HLDoT(1);
	m=tot;
	build(1,1,m);
	rep(i,0,Q) {
		scanf("%d",&ty);
		if (ty==1) {
			scanf("%d%d%d",&u,&v,&k);
			ret.clear();
			while (k>0) {
				z=mp(inf,mp(0,0));
				query(u,v);
				if (z.fi>=1ll<<50) break;
				--k;
				ret.pb(z.se.se);
				modify(1,1,m,pos[z.se.se],pos[z.se.se],inf);
			}
			printf("%d",SZ(ret));
			for (auto u:ret) printf(" %d",u);
			puts("");
		} else {
			scanf("%d%d",&u,&k);
			modify(1,1,m,l[u],r[u],k);
		}
	}
}