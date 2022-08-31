#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
bitset<1000> nd[4*N],pr,ret;
int cyc[4*N],l[N],r[N],id[N],tot,n,m,q,ty,x,u,v,a[N];
VI e[N];
bool prime(int x) {
	for (int i=2;i<x;i++) if (x%i==0) return 0;
		return 1;
}
void rotate(int p,int x) {
	cyc[p]+=x;
	nd[p]=(nd[p]<<x)|(nd[p]>>(m-x));
}
void push(int p) {
	cyc[p]%=m;
	if (cyc[p]) {
		rotate(p+p,cyc[p]);
		rotate(p+p+1,cyc[p]);
		cyc[p]=0;
	}
}
void dfs(int u,int f) {
	id[l[u]=++tot]=u; 
	for (auto v:e[u]) if (v!=f) dfs(v,u);
	r[u]=tot;
}
void query(int p,int l,int r,int tl,int tr) {
	if (l==tl&&r==tr) ret|=nd[p];
	else {
		int md=(l+r)>>1;
		push(p);
		if (tr<=md) query(p+p,l,md,tl,tr);
		else if (tl>md) query(p+p+1,md+1,r,tl,tr);
		else query(p+p,l,md,tl,md),query(p+p+1,md+1,r,md+1,tr);
	}
}
void modify(int p,int l,int r,int tl,int tr,int x) {
	if (l==tl&&r==tr) {
		rotate(p,x);
	} else {
		int md=(l+r)>>1;
		push(p);
		if (tr<=md) modify(p+p,l,md,tl,tr,x);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,x);
		else modify(p+p,l,md,tl,md,x),modify(p+p+1,md+1,r,md+1,tr,x);
		nd[p]=nd[p+p]|nd[p+p+1];
	}
}
void build(int p,int l,int r) {
	if (l==r) {
		nd[p][a[id[l]]%m].flip();
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		nd[p]=nd[p+p]|nd[p+p+1];
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,2,m) if (prime(i)) pr[i].flip();
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1,0);
	build(1,1,n);
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d",&ty);
		if (ty==2) {
			scanf("%d",&u);
			ret=0;
			query(1,1,n,l[u],r[u]);
			ret=ret&pr;
			printf("%d\n",(int)(ret.count()));
		} else {
			scanf("%d%d",&u,&x);
			x%=m;
			modify(1,1,n,l[u],r[u],x);
		}
	}
}