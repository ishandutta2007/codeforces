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

const int M=500000;
int n,x;
struct node {
	int fg,sp;
	PII mv;
}nd[8*M+100];
void upd(int p) {
	nd[p].mv=min(nd[p+p].mv,nd[p+p+1].mv);
	nd[p].sp=nd[p+p].sp+nd[p+p+1].sp;
}
void setf(int p,int v) { nd[p].fg+=v; nd[p].mv.fi+=v; }
void build(int p,int l,int r) {
	nd[p].mv=mp(l,l);
	if (l!=r) {
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
PII query(int p,int l,int r,int tl,int tr) {
	if (tl==l&&tr==r) return nd[p].mv;
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return min(query(p+p,l,md,tl,md),query(p+p+1,md+1,r,md+1,tr));
	}
}
int sum(int p,int l,int r,int tl,int tr) {
	if (tl>tr) return 0;
	if (tl==l&&tr==r) return nd[p].sp;
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return sum(p+p,l,md,tl,tr);
		else if (tl>md) return sum(p+p+1,md+1,r,tl,tr);
		else return sum(p+p,l,md,tl,md)+sum(p+p+1,md+1,r,md+1,tr);
	}
}

void modify(int p,int l,int r,int tl,int tr,int v) {
	if (tl>tr) return;
	if (tl==l&&tr==r) { setf(p,v); return; }
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,v);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,v);
		else modify(p+p,l,md,tl,md,v),modify(p+p+1,md+1,r,md+1,tr,v);
		upd(p);
	}
}
void change(int p,int l,int r,int x) {
	if (l==r) nd[p].sp++;
	else {
		push(p);
		int md=(l+r)>>1;
		if (x<=md) change(p+p,l,md,x);
		else if (x>md) change(p+p+1,md+1,r,x);
		upd(p);
	}
}

int ask(int p,int l,int r,int fl) {
	if (l==r) {
		return l;
	} else {
		push(p);
		int md=(l+r)>>1;
		if (fl+nd[p+p].sp>=M-md) return ask(p+p,l,md,fl);
		else return ask(p+p+1,md+1,r,fl+nd[p+p].sp);
	}
}
int main() {
	scanf("%d",&n);
	build(1,0,2*M);
	rep(i,0,n) {
		scanf("%d",&x); x+=M;
		modify(1,0,2*M,x,2*M,-1);
		change(1,0,2*M,x);
		int posl=ask(1,0,2*M,0);
		PII r=query(1,0,2*M,posl+1,2*M);
		r=min(r,mp(posl-sum(1,0,2*M,0,posl),posl));
		printf("%d\n",r.se+sum(1,0,2*M,r.se+1,2*M)-M);
	}
}