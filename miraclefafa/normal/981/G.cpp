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
const ll mod=998244353;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;

struct node {
	ll s,v1,v2;
	int sz;
}nd[4*N];
void upd(int p) {
	nd[p].s=(nd[p+p].s+nd[p+p+1].s)%mod;
}
void setf(int p,ll v1,ll v2) {
	nd[p].s=(nd[p].s*v1+nd[p].sz*v2)%mod;
	nd[p].v1=nd[p].v1*v1%mod;
	nd[p].v2=(nd[p].v2*v1+v2)%mod;
}
void build(int p,int l,int r) {
	nd[p].v1=1;
	nd[p].sz=r-l+1;
	if (l==r) {
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
}
void push(int p) {
	if (nd[p].v1!=1||nd[p].v2!=0) {
		setf(p+p,nd[p].v1,nd[p].v2);
		setf(p+p+1,nd[p].v1,nd[p].v2);
		nd[p].v1=1;
		nd[p].v2=0;
	}
}
ll query(int p,int l,int r,int tl,int tr) {
	if (tl==l&&tr==r) return nd[p].s;
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return (query(p+p,l,md,tl,md)+query(p+p+1,md+1,r,md+1,tr))%mod;
	}
}
void modify(int p,int l,int r,int tl,int tr,int v1,int v2) {
//	if (p==1) printf("modi %d %d %d %d\n",tl,tr,v1,v2);
	if (tl>tr) return;
	if (tl==l&&tr==r) return setf(p,v1,v2);
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,v1,v2);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,v1,v2);
		else modify(p+p,l,md,tl,md,v1,v2),modify(p+p+1,md+1,r,md+1,tr,v1,v2);
		upd(p);
	}
}

int n,q,ty,l,r,x;
set<PII> emp[N];
void split(int x,int l) {
	auto it=emp[x].lower_bound(mp(l,l));
	if (it!=emp[x].begin()) {
		--it;
		auto p=*it;
		if (p.se>=l) {
			emp[x].erase(p);
			emp[x].insert(mp(p.fi,l-1));
			emp[x].insert(mp(l,p.se));
		}
	}
}

int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) emp[i].insert(mp(1,n));
	build(1,1,n);
	rep(i,0,q) {
		scanf("%d%d%d",&ty,&l,&r);
		if (ty==1) {
			scanf("%d",&x);
			modify(1,1,n,l,r,2,0);
			split(x,l);
			split(x,r+1);
			while (1) {
				auto it=emp[x].lower_bound(mp(l,l));
				if (it==emp[x].end()||it->fi>r) break;
				modify(1,1,n,it->fi,it->se,(mod+1)/2,1);
				emp[x].erase(it);
			}
		} else {
			printf("%lld\n",query(1,1,n,l,r));
		}
	}
}