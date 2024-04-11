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

const int N=101000;
ll tmp[20];
int a[N];
struct node {
	ll s[10];
	int fg[10];
}nd[4*N];
int n,q,ty,l,r,k,v;
void upd(int p) {
	rep(i,0,10) nd[p].s[i]=0;
	rep(i,0,10) nd[p].s[nd[p+p].fg[i]]+=nd[p+p].s[i];
	rep(i,0,10) nd[p].s[nd[p+p+1].fg[i]]+=nd[p+p+1].s[i];
}
void setf(int p,int k,int v) {
	rep(i,0,10) if (nd[p].fg[i]==k) { nd[p].fg[i]=v;}
}
void build(int p,int l,int r) {
	rep(i,0,10) nd[p].fg[i]=i;
	if (l==r) {
		ll pw=1;
		while (a[l]) {
			nd[p].s[a[l]%10]+=pw; pw*=10; a[l]/=10;
		}
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
/*	printf("%d:",p);
	rep(i,0,10) printf(" %lld",nd[p].s[i]); puts("");*/
}
void push(int p) {
	rep(i,0,10) nd[p+p].fg[i]=nd[p].fg[nd[p+p].fg[i]];
	rep(i,0,10) nd[p+p+1].fg[i]=nd[p].fg[nd[p+p+1].fg[i]];
	rep(i,0,10) tmp[i]=0;
	rep(i,0,10) tmp[nd[p].fg[i]]+=nd[p].s[i];
	rep(i,0,10) nd[p].s[i]=tmp[i],nd[p].fg[i]=i;
}
ll query(int p,int l,int r,int tl,int tr) {
	if (tl==l&&tr==r) {
		ll s=0;
		rep(i,0,10) s+=nd[p].s[i]*nd[p].fg[i];
		return s;
	} else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return query(p+p,l,md,tl,md)+query(p+p+1,md+1,r,md+1,tr);
	}
}
void modify(int p,int l,int r,int tl,int tr,int k,int v) {
	if (tl>tr) return;
	if (tl==l&&tr==r) {
		setf(p,k,v);
	} else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,k,v);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,k,v);
		else modify(p+p,l,md,tl,md,k,v),modify(p+p+1,md+1,r,md+1,tr,k,v);
		upd(p);
	}
}
int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) scanf("%d",a+i);
	build(1,1,n);
	rep(i,0,q) {
		scanf("%d%d%d",&ty,&l,&r);
		if (ty==2) {
			printf("%lld\n",query(1,1,n,l,r));
		} else {
			scanf("%d%d",&k,&v);
			modify(1,1,n,l,r,k,v);
		}
	}
}