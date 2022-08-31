#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
struct info {
	int fg,s0,s1,s2;
}nd[N*4];
vector<PII> e[N],que[N];
int n,u,v,w,q,l[N],r[N],tot,ret[N];
void setf(int p,ll d) {
	nd[p].fg=(nd[p].fg+d)%mod;
	nd[p].s2=(nd[p].s2+d*d%mod*nd[p].s0+2*d*nd[p].s1)%mod;
	nd[p].s1=(nd[p].s1+d*nd[p].s0)%mod;
}
void push(int p) {
	if (nd[p].fg!=0) {
		setf(p+p,nd[p].fg);
		setf(p+p+1,nd[p].fg);
		nd[p].fg=0;
	}
}
void build(int p,int l,int r) {
	nd[p].s0=r-l+1;
	if (l!=r) {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
	}
}
void modify(int p,int l,int r,int tl,int tr,int d) {
	if (l==tl&&r==tr) {
		setf(p,d);
	} else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,d);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,d);
		else modify(p+p,l,md,tl,md,d),modify(p+p+1,md+1,r,md+1,tr,d);
		nd[p].s1=(nd[p+p].s1+nd[p+p+1].s1)%mod;
		nd[p].s2=(nd[p+p].s2+nd[p+p+1].s2)%mod;
	}
}
int query(int p,int l,int r,int tl,int tr) {
	if (l==tl&&r==tr) {
		return nd[p].s2;
	} else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return (query(p+p,l,md,tl,md)+query(p+p+1,md+1,r,md+1,tr))%mod;
	}
}

void dfs(int u,int f,int val) {
	l[u]=++tot;
	modify(1,1,n,tot,tot,val);
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f) continue;
		dfs(v,u,(val+p.se)%mod);
	}
	r[u]=tot;
}
void dfs2(int u,int f) {
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f) continue;
		modify(1,1,n,1,n,p.se);
		modify(1,1,n,l[v],r[v],(mod-p.se)*2%mod);
		dfs2(v,u);
		modify(1,1,n,1,n,mod-p.se);
		modify(1,1,n,l[v],r[v],p.se*2%mod);
	}
	for (auto p:que[u]) {
		int v=p.fi,id=p.se;
		ret[id]=(2*query(1,1,n,l[v],r[v])-query(1,1,n,1,n))%mod;
		if (ret[id]<0) ret[id]+=mod;
	}
}
int main() {
//	freopen("D.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d%d",&u,&v,&w);
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	build(1,1,n);
	dfs(1,0,0);
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%d",&u,&v);
		que[u].pb(mp(v,i));
	}
	dfs2(1,0);
	rep(i,0,q) printf("%d\n",ret[i]);
}