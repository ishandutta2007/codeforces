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

struct node {
	node *l,*r;
	int tag,mn,mx;
}pool[20100000],*cur=pool;

map<int,node*> nd;
const int M=1000000000;
node *add(node *p,int v) {
	node *q=cur++; *q=*p;
	q->tag+=v; q->mn+=v; q->mx+=v;
	return q;
}


node *build(int l,int r) {
	if (nd.count(r-l)) return nd[r-l];
	if (l==r) {
		node *p=cur++;
		p->tag=p->mn=p->mx=0;
		return nd[0]=p;
	} else {
		int md=(l+r)>>1;
		node *p=cur++;
		p->l=build(l,md);
		p->r=add(build(md+1,r),md-l+1);
		p->mn=p->l->mn;
		p->mx=p->r->mx;
		return nd[r-l]=p;
	}
}
int find(node *p,int l,int r,int v) {
	if (v>p->mx) return r+1;
	if (l==r) return r;
	v-=p->tag;
	int md=(l+r)>>1;
	if (v<=p->l->mx) return find(p->l,l,md,v);
	else return find(p->r,md+1,r,v);
}
node* modify(node *p,int l,int r,int tl,int tr,int v) {
	if (tl>tr) return p;
	node *q=cur++; *q=*p;
	if (tl==l&&tr==r) {
		q->tag+=v; q->mn+=v; q->mx+=v;
		return q;
	} else {
		int md=(l+r)>>1;
		if (tr<=md) q->l=modify(p->l,l,md,tl,tr,v);
		else if (tl>md) q->r=modify(p->r,md+1,r,tl,tr,v);
		else q->l=modify(p->l,l,md,tl,md,v),q->r=modify(p->r,md+1,r,md+1,tr,v);
		q->mn=q->l->mn+q->tag;
		q->mx=q->r->mx+q->tag;
		return q;
	}
}
int query(node *p,int l,int r,int pos) {
	if (l==r) return p->tag;
	else {
		int md=(l+r)>>1;
		if (pos<=md) return p->tag+query(p->l,l,md,pos);
		else return p->tag+query(p->r,md+1,r,pos);
	}
}


int main() {
	int n;
	int ans=0;
	scanf("%d",&n);
	auto T=build(0,M);
	rep(i,1,n+1) {
		int x,k;
		scanf("%d",&x);
		int p1=find(T,0,M,x);
		int p2=find(T,0,M,x+1);
		T=modify(T,0,M,0,p1-1,1);
		//puts("------");
		T=modify(T,0,M,p2,M,-1);
		//puts("------");
		scanf("%d",&k);
		rep(i,0,k) {
			scanf("%d",&x);
			x=(x+ans)%1000000001;
			ans=query(T,0,M,x);
			printf("%d\n",ans);
		}
	}
}