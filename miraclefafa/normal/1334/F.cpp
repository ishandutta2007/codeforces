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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=501000;
struct node {
	ll fg;
	ll val;
}nd[4*N];
void upd(int p) {

}
void setf(int p,ll v) {
	nd[p].fg+=v;
	nd[p].val+=v;
}
void build(int p,int l,int r) {
	nd[p].fg=0;
	nd[p].val=1ll<<60;
	if (l==r) {
		if (l==0) nd[p].val=0;
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
ll query(int p,int l,int r,int x) {
	if (l==r) return nd[p].val;
	else {
		push(p);
		int md=(l+r)>>1;
		if (x<=md) return query(p+p,l,md,x);
		else return query(p+p+1,md+1,r,x);
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

int n,a[N],p[N],b[N],m;

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) scanf("%d",p+i);
	scanf("%d",&m);
	rep(i,1,m+1) scanf("%d",b+i);
	b[m+1]=1<<30;
	build(1,0,m);
	rep(i,1,n+1) {
		int j=lower_bound(b+1,b+m+1,a[i])-b;
		if (b[j]==a[i]) {
			modify(1,0,m,j+1,m,min(p[i],0));
			ll a=query(1,0,m,j);
			ll x=a+min(p[i],0),y=query(1,0,m,j-1);
			modify(1,0,m,j,j,min(x,y)-a);
			modify(1,0,m,0,j-1,p[i]);
		} else {
			modify(1,0,m,j,m,min(p[i],0));
			modify(1,0,m,0,j-1,p[i]);
		}
		//rep(j,0,m+1) printf("%lld ",query(1,0,m,j));
		//puts("");
	}
	ll a=query(1,0,m,m);
	if (a>=1ll<<55) puts("NO"); else printf("YES\n%lld\n",a);
}