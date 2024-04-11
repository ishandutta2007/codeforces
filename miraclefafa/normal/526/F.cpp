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

const int N=301000;
int smn[N],smx[N],p[N];
int n,x,y,tmn,tmx;
struct node {
	int fg;
	PII s;
}nd[N*4];
void setf(int p,int x) {
	nd[p].fg+=x; nd[p].s.fi+=x;
}
void push(int p) {
	setf(p+p,nd[p].fg);
	setf(p+p+1,nd[p].fg);
	nd[p].fg=0;
}
inline PII merge(PII a,PII b) {
	if (a.fi<b.fi) return a; else if (a.fi>b.fi) return b;
	else return mp(a.fi,a.se+b.se);
}
void build(int p,int l,int r) {
	nd[p].s=mp(0,r-l+1);
	if (l!=r) {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
	}
}
void add(int p,int l,int r,int tl,int tr,int x) {
	if (tl==l&&tr==r) setf(p,x);
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) add(p+p,l,md,tl,tr,x);
		else if (tl>md) add(p+p+1,md+1,r,tl,tr,x);
		else add(p+p,l,md,tl,md,x),add(p+p+1,md+1,r,md+1,tr,x);
		nd[p].s=merge(nd[p+p].s,nd[p+p+1].s);
	}
}
PII query(int p,int l,int r,int tl,int tr) {
	if (tl==l&&tr==r) return nd[p].s;
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return merge(query(p+p,l,md,tl,md),query(p+p+1,md+1,r,md+1,tr));
	}
}

int main() {
//	freopen("in.txt","r",stdin);
	ll ans=0;
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d%d",&x,&y);
		p[x]=y;
	}
	build(1,1,n);
	rep(i,1,n+1) {
		// seg
		while (tmn>0&&p[smn[tmn]]>p[i]) add(1,1,n,smn[tmn-1]+1,smn[tmn],p[smn[tmn]]-p[i]),tmn--;
		smn[++tmn]=i;
		while (tmx>0&&p[smx[tmx]]<p[i]) add(1,1,n,smx[tmx-1]+1,smx[tmx],p[i]-p[smx[tmx]]),tmx--;
		smx[++tmx]=i;
		add(1,1,n,i,i,i);
		PII ret=query(1,1,n,1,i);
		assert(ret.fi==i);
		ans+=ret.se;
	}
	printf("%I64d\n",ans);
}