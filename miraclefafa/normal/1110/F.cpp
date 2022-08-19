#include <bits/stdc++.h>
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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=501000;
ll val[N];
struct node {
	ll fg,s;
}nd[4*N];
void upd(int p) {
	nd[p].s=min(nd[p+p].s,nd[p+p+1].s);
}
void setf(int p,ll v) {
	nd[p].fg+=v;
	nd[p].s+=v;
}
void build(int p,int l,int r) {
	nd[p].fg=0;
	if (l==r) {
		nd[p].s=val[l];
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
ll query(int p,int l,int r,int tl,int tr) {
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

int cnt,n,q,p,v;
int l[N],r[N];
vector<PII> s[N]; 
ll ans[N],offset;
vector<pair<PII,int>> que[N];
void dfs(int u,ll dep) {
	++cnt;
	assert(u==cnt);
	l[u]=cnt;
	val[u]=s[u].empty()?dep:1ll<<60;
	for (auto p:s[u]) {
		dfs(p.fi,dep+p.se);
	}
	r[u]=cnt;
}

void dfs2(int u) {
	for (auto qq:que[u]) {
		int l=qq.fi.fi;
		int r=qq.fi.se;
		ans[qq.se]=query(1,1,n,l,r)+offset;
	}
	for (auto p:s[u]) {
		int v=p.fi;
		offset+=p.se;
		modify(1,1,n,l[v],r[v],-2*p.se);
		dfs2(v);
		offset-=p.se;
		modify(1,1,n,l[v],r[v],2*p.se);
	}
}
int main() {
	scanf("%d%d",&n,&q);
	rep(i,2,n+1) {
		scanf("%d%d",&p,&v);
		s[p].pb(mp(i,v));
	}
	dfs(1,0);
	rep(i,0,q) {
		int l,r;
		scanf("%d%d%d",&v,&l,&r);
		que[v].pb(mp(mp(l,r),i));
	}
	build(1,1,n);
	dfs2(1);
	rep(i,0,q) printf("%lld\n",ans[i]);
}