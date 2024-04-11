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
	ll fg,l,r;
	int ld,lu,rd,ru,f,sz;
}nd[4*N];
int a[N],l,r,v,n,m;
void upd(int p) {
	bool lg=nd[p+p].r>nd[p+p+1].l,rg=nd[p+p].r<nd[p+p+1].l;
	if (nd[p+p].ld==nd[p+p].sz&&lg) 
		nd[p].ld=nd[p+p].sz+nd[p+p+1].ld;
	else nd[p].ld=nd[p+p].ld;
	if (nd[p+p+1].rd==nd[p+p+1].sz&&rg)
		nd[p].rd=nd[p+p+1].sz+nd[p+p].rd;
	else nd[p].rd=nd[p+p+1].rd;
	if (nd[p+p].lu==nd[p+p].sz) {
		if (nd[p+p].rd==nd[p+p].sz) {
			if (rg) nd[p].lu=nd[p+p].sz+nd[p+p+1].lu;
			if (lg) nd[p].lu=nd[p+p].sz+nd[p+p+1].ld;
			if (!lg&&!rg) nd[p].lu=nd[p+p].sz;
		} else {
			if (!lg) nd[p].lu=nd[p+p].sz;
			if (lg) nd[p].lu=nd[p+p].sz+nd[p+p+1].ld;
		}
	} else nd[p].lu=nd[p+p].lu;
	if (nd[p+p+1].ru==nd[p+p+1].sz) {
		if (nd[p+p+1].ld==nd[p+p+1].sz) {
			if (lg) nd[p].ru=nd[p+p+1].sz+nd[p+p].ru;
			if (rg) nd[p].ru=nd[p+p+1].sz+nd[p+p].rd;
			if (!lg&&!rg) nd[p].ru=nd[p+p+1].sz;
		} else {
			if (!rg) nd[p].ru=nd[p+p+1].sz;
			if (rg) nd[p].ru=nd[p+p+1].sz+nd[p+p].rd;
		}
	} else nd[p].ru=nd[p+p+1].ru;
	nd[p].f=max(nd[p+p].f,nd[p+p+1].f);
	if (lg) nd[p].f=max(nd[p].f,nd[p+p].ru+nd[p+p+1].ld);
	if (rg) nd[p].f=max(nd[p].f,nd[p+p].rd+nd[p+p+1].lu);
	nd[p].l=nd[p+p].l;
	nd[p].r=nd[p+p+1].r;
}
void setf(int p,ll v) {
	nd[p].fg+=v; nd[p].l+=v; nd[p].r+=v;
}
void build(int p,int l,int r) {
	nd[p].fg=0;
	nd[p].sz=r-l+1;
	nd[p].l=a[l]; nd[p].r=a[r];
	if (l==r) {
		nd[p].fg=0;
		nd[p].ld=nd[p].lu=nd[p].rd=nd[p].ru=nd[p].f=1;
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

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	build(1,1,n);
	scanf("%d",&m);
//	printf("%d\n",nd[1].f);
	rep(i,0,m) {
		scanf("%d%d%d",&l,&r,&v);
		modify(1,1,n,l,r,v);
		printf("%d\n",nd[1].f);
	}
}