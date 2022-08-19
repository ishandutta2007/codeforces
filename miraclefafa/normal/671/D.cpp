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
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=301000;
struct node {
	ll fg,v;
}nd[4*N];
multiset<ll> s[N];
int n,m,u,v,c,l[N],r[N],tot;
VI e[N];
vector<PII> t[N];
ll dp[N];
void upd(int p) {
	nd[p].v=min(nd[p+p].v,nd[p+p+1].v);
}
void setf(int p,ll v) {
	nd[p].fg+=v; nd[p].v+=v;
}
void build(int p,int l,int r) {
	nd[p].fg=0;
	nd[p].v=1ll<<60;
	if (l==r) {
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
	if (tl==l&&tr==r) return nd[p].v;
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return min(query(p+p,l,md,tl,md),query(p+p+1,md+1,r,md+1,tr));
	}
}
void add(int p,int l,int r,int tl,int tr,ll v) {
	if (tl>tr) return;
	if (tl==l&&tr==r) return setf(p,v);
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) add(p+p,l,md,tl,tr,v);
		else if (tl>md) add(p+p+1,md+1,r,tl,tr,v);
		else add(p+p,l,md,tl,md,v),add(p+p+1,md+1,r,md+1,tr,v);
		upd(p);
	}
}
void modify(int p,int l,int r,int x,ll v) {
	if (l==r) nd[p].v=v;
	else {
		push(p);
		int md=(l+r)>>1;
		if (x<=md) modify(p+p,l,md,x,v);
		else if (x>md) modify(p+p+1,md+1,r,x,v);
		upd(p);		
	}
}

void dfs(int u,int f) {
	l[u]=++tot;
	for (auto v:e[u]) {
		if (v==f) continue;
		dfs(v,u);
	}
	r[u]=tot;
}
void solve(int u,int f) {
	ll sm=0;
	for (auto v:e[u]) {
		if (v==f) continue;
		solve(v,u);
		sm+=dp[v];
	}
	//modify(1,1,n,l[u],l[u],sm);
	if (u==1) {
		printf("%lld\n",sm);
		exit(0);
	}
	for (auto v:e[u]) {
		if (v==f) continue;
		add(1,1,n,l[v],r[v],sm-dp[v]);
//		printf("Add %d %d %lld\n",l[v],r[v],sm-dp[v]);
	}
	for (auto p:t[u]) {
		int v=p.fi;
		ll pre=*s[v].begin();
		s[v].erase(s[v].find(p.se));
		ll nxt=s[v].empty()?1ll<<60:*s[v].begin();
		add(1,1,n,l[v],l[v],nxt-pre);
//		printf("Add %d %d %lld\n",l[v],l[v],nxt-pre);
	}
	if (SZ(s[u])) {
		modify(1,1,n,l[u],sm+*s[u].begin());
//		printf("Modify %d %lld\n",l[u],sm+*s[u].begin());
	}
	dp[u]=query(1,1,n,l[u],r[u]);
//	printf("%d %lld\n",u,dp[u]);
	if (dp[u]>=1ll<<60) {
		puts("-1");
		exit(0);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1,0);
	rep(i,0,m) {
		scanf("%d%d%d",&u,&v,&c);
		s[u].insert(c);
		t[v].pb(mp(u,c));
	}
	build(1,1,n);
	solve(1,0);
}