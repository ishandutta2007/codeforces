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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=123456;
struct node {
	int mn,mcnt,mf,fg;
	ll s;
}nd[N*4];
int n,q,l,r,p[N];
ll ans[N];
vector<PII> qr[N];
stack<pair<PII,int>> s1,s2;

void build(int p,int l,int r) {
	nd[p].mn=l;
	nd[p].mcnt=1;
	int md=(l+r)>>1;
	if (l!=r) {
		build(p+p,l,md);
		build(p+p+1,md+1,r);
	}
}

void setf1(int p,int fg) {
	nd[p].fg+=fg; nd[p].mn+=fg;
}
void setf2(int p,ll fg) {
	nd[p].mf+=fg; nd[p].s+=nd[p].mcnt*fg;
}

void push(int p) {
	if (nd[p].fg) {
		setf1(p+p,nd[p].fg);
		setf1(p+p+1,nd[p].fg);
		nd[p].fg=0;
	}
	if (nd[p].mf) {
		if (nd[p].mn==nd[p+p].mn) setf2(p+p,nd[p].mf);
		if (nd[p].mn==nd[p+p+1].mn) setf2(p+p+1,nd[p].mf);
		nd[p].mf=0;
	}
}

void upd(int p) {
	nd[p].mn=min(nd[p+p].mn,nd[p+p+1].mn);
	nd[p].mcnt=0;
	if (nd[p].mn==nd[p+p].mn) nd[p].mcnt+=nd[p+p].mcnt;
	if (nd[p].mn==nd[p+p+1].mn) nd[p].mcnt+=nd[p+p+1].mcnt;
	nd[p].s=nd[p+p].s+nd[p+p+1].s;
}

void modify(int p,int l,int r,int tl,int tr,int v) {
	if (l==tl&&r==tr) setf1(p,v);
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,v);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,v);
		else modify(p+p,l,md,tl,md,v),modify(p+p+1,md+1,r,md+1,tr,v);
		upd(p);
	}
}
ll query(int p,int l,int r,int tl,int tr) {
	if (l==tl&&r==tr) return nd[p].s;
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return query(p+p,l,md,tl,md)+query(p+p+1,md+1,r,md+1,tr);
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",p+i);
	build(1,1,n);
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%d",&l,&r);
		qr[r].pb(mp(l,i));
	}
	rep(i,1,n+1) {
		modify(1,1,n,1,n,-1);
		int pl=i;
		while (!s1.empty()) {
			if (s1.top().se>p[i]) {
				modify(1,1,n,s1.top().fi.fi,s1.top().fi.se,s1.top().se);
				pl=s1.top().fi.fi;
				s1.pop();
			} else break;
		}
		int ql=i;
		while (!s2.empty()) {
			if (s2.top().se<p[i]) {
				modify(1,1,n,s2.top().fi.fi,s2.top().fi.se,-s2.top().se);
				ql=s2.top().fi.fi;
				s2.pop();
			} else break;
		}
		s1.push(mp(mp(pl,i),p[i]));
		s2.push(mp(mp(ql,i),p[i]));
		modify(1,1,n,pl,i,-p[i]);
		modify(1,1,n,ql,i,p[i]);
		setf2(1,1);
		for (auto p:qr[i]) ans[p.se]=query(1,1,n,p.fi,i);

	}
	rep(i,0,q) printf("%lld\n",ans[i]);
}