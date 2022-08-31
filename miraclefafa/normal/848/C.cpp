#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <random>
#include <ctime>
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

#define prev adfasdf
#define next saddfasf

mt19937 rng(time(0));
const int N=101000;
int a[N],pre[N],n,m,ty,p,q;
set<int> hs[N];
int prev(int pos) {
	auto it=hs[a[pos]].lower_bound(pos);
	return *(--it);
}
int next(int pos) {
	auto it=hs[a[pos]].upper_bound(pos);
	return *it;
}


struct node {
	int wt,key,d;
	ll sm;
	node *s[2];
	void push() {
	}
	void upd() {
		sm=d;
		if (s[0]) sm+=s[0]->sm;
		if (s[1]) sm+=s[1]->sm;
	}
}pool[N*70],*cur=pool,*rt;
node *newnode(int w,int s) {
	node *q=cur++;
	q->sm=s; q->d=s; q->key=w;
	q->wt=rng();
	return q;
}
void merge(node *&p,node *l,node *r) {
	if (!l||!r) p=l?l:r;
	else if (l->wt<r->wt) {
		merge(l->s[1],l->s[1],r);
		(p=l)->upd();
	} else {
		merge(r->s[0],l,r->s[0]);
		(p=r)->upd();
	}
}
void split(node *p,node *&l,node *&r,int x) {
	if (p==0) {
		l=0; r=0;
	} else {
		if (p->key>x) r=p,split(p->s[0],l,r->s[0],x),r->upd();
		else l=p,split(p->s[1],l->s[1],r,x),l->upd();
	}
}


struct Tnode {
	node *p;
}nd[4*N];
void build(int p,int l,int r) {
	for (int i=l;i<=r;i++) {
		node *x,*y,*z;
		split(nd[p].p,x,z,pre[i]);
		y=newnode(pre[i],i-pre[i]);
		merge(x,x,y);
		merge(nd[p].p,x,z);
	}
	if (l==r) {
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
	}
}
ll query(int p,int l,int r,int tl,int tr,int v1,int v2) {
	if (tl==l&&tr==r) {
		node *x,*y;
		split(nd[p].p,x,y,v1-1);
		ll ret=(y?y->sm:0);
		merge(nd[p].p,x,y);
		return ret;
	} else {
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr,v1,v2);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr,v1,v2);
		else return query(p+p,l,md,tl,md,v1,v2)+query(p+p+1,md+1,r,md+1,tr,v1,v2);
	}
}
void del(int p,int l,int r,int v,int w) {
	node *x,*y,*z;
	split(nd[p].p,x,y,w-1);
	split(y,y,z,w);
	merge(nd[p].p,x,z);
	if (l==r) {
	} else {
		int md=(l+r)>>1;
		if (v<=md) del(p+p,l,md,v,w);
		else if (v>md) del(p+p+1,md+1,r,v,w);
	}
}

void ins(int p,int l,int r,int v,int w) {
	node *x,*y,*z;
	split(nd[p].p,x,z,w);
	y=newnode(w,v-w);
	merge(x,x,y);
	merge(nd[p].p,x,z);
	if (l==r) {
	} else {
		int md=(l+r)>>1;
		if (v<=md) ins(p+p,l,md,v,w);
		else if (v>md) ins(p+p+1,md+1,r,v,w);
	}
}

vector<VI> dd,ii;
void modify(int p,int q) {
//	del(1,1,n,p,ty);
	dd.pb(VI{p,pre[p]});
	pre[p]=q;
	ii.pb(VI{p,pre[p]});
//	ins(1,1,n,p,ty);
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) {
		scanf("%d",a+i);
		hs[a[i]].insert(i);
	}
	rep(i,1,n+1) {
		hs[i].insert(-i),hs[i].insert(i+n);
	}
	rep(i,1,n+1) {
		pre[i]=prev(i);
	}
	build(1,1,n);

	rep(i,0,m) {
		scanf("%d%d%d",&ty,&p,&q);
		if (ty==1) {
			if (a[p]==q) continue;
			dd.clear(); ii.clear();
			if (next(p)<=n) modify(next(p),pre[p]);
			hs[a[p]].erase(p);
			hs[q].insert(p);
			a[p]=q;
			int np0=prev(p),np1=next(p);
			modify(p,np0);
			if (np1<=n) modify(np1,p);
			for (auto v:dd) {
//				printf("dd %d %d %d\n",v[0],v[1],v[2]);
				del(1,1,n,v[0],v[1]);
			}
			for (auto v:ii) {
//				printf("ii %d %d %d\n",v[0],v[1],v[2]);
				ins(1,1,n,v[0],v[1]);
			}
		} else {
			printf("%lld\n",query(1,1,n,p,q,p,q));
		}
//		rep(j,1,n+1) printf("%d %d %d\n",j,pre[j][0],pre[j][1]);
	}
}