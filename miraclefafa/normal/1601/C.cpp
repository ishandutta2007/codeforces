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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=2010000;
int n,m,t,_;
int a[N],b[N],c1[N],c2[N],cntb[N];
VI vv[N];
int query(int *c,int x) {
	int s=0;
	for (;x;x-=x&-x) s+=c[x];
	return s;
}

void modify(int *c,int x,int s) {
	for (;x<=t;x+=x&-x) c[x]+=s;
}

struct node {
	int sm,ms;
}nd[4*N];
void upd(int p) {
	nd[p].sm=nd[p+p].sm+nd[p+p+1].sm;
	nd[p].ms=min({0,nd[p+p].ms,nd[p+p].sm+nd[p+p+1].ms});
	assert(nd[p].ms<=0);
}
void setf(int p,int v) {
}
void build(int p,int l,int r) {
	if (l==r) {
		nd[p].sm=1; nd[p].ms=0;
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
}
void push(int p) {
}
void change(int p,int l,int r,int x,int v) {
	if (l==r) nd[p].sm=v,nd[p].ms=min(v,0);
	else {
		push(p);
		int md=(l+r)>>1;
		if (x<=md) change(p+p,l,md,x,v);
		else change(p+p+1,md+1,r,x,v);
		upd(p);
	}
}


void solve() {
	VI v;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%d",a+i),v.pb(a[i]);
	rep(i,1,m+1) scanf("%d",b+i),v.pb(b[i]);
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	t=SZ(v);
	rep(i,1,t+1) cntb[i]=0,vv[i].clear();
	rep(i,1,n+1) {
		a[i]=lower_bound(all(v),a[i])-v.begin()+1;
		vv[a[i]].pb(i);
	}
	rep(i,1,m+1) {
		b[i]=lower_bound(all(v),b[i])-v.begin()+1;
		cntb[b[i]]++;
	}
	ll ans=0;
	rep(i,1,t+1) c1[i]=c2[i]=0;
	rep(i,1,n+1) {
		ans+=i-1-query(c1,a[i]);
		modify(c1,a[i],1);
	}
	int les=0;
	build(1,1,n);
	rep(i,1,t+1) {
		for (auto x:vv[i]) change(1,1,n,x,0);
		//printf("zz %d %d %d\n",i,nd[1].ms,les);
		ans+=(ll)(les+nd[1].ms)*cntb[i];
		les+=SZ(vv[i]);
		for (auto x:vv[i]) change(1,1,n,x,-1);

	}
	printf("%lld\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}