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

const int N=101000,LOGN=17,inf=1<<30;
multiset<int> pool[N],*cur=pool,ts;
typedef multiset<int>* pset;
pset rt[N];
int l[N],r[N],id[N],sz[N],tot,ret[N],n,u,v,R;
VI e[N];
struct node {
	node *s[2];
	int val;
}qpool[30000000],*qcur=qpool,*Tot;
void dfs(int u,int f)  {
	id[l[u]=++tot]=u;
	sz[u]=1;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
		sz[u]+=sz[v];
	}
	r[u]=tot;
}
pset merge(pset &a,pset &b) {
	if (a->size()<b->size()) swap(a,b);
	for (auto v:*b) a->insert(v);
	b->clear();
	return a;
}
node* modify(node *q,int v,int s) {
	per(i,0,LOGN) {
		int w=(v>>i)&1;
		node *p=qcur+i+1; *p=*q;
		p->val+=s;
		p->s[w]=qcur+i;
		q=q->s[w];
	}
	*qcur=*q;
	qcur->val+=s;
	rep(i,1,LOGN+1) {
		node *p=qcur+i;
		assert(p->val==p->s[0]->val+p->s[1]->val);
	}
	qcur+=LOGN+1;
	return qcur-1;
}
int query(node *q,int v,int d) {
//	printf("%d %d %d\n",v,d,q->val);
	if (d==0) {
		if (q->val==0) return inf;
		else return 0;
	} else {
		assert(q->val==q->s[0]->val+q->s[1]->val);
		int w=(v>>(d-1))&1;
		if (w==0&&q->s[0]->val) {
			int c=query(q->s[0],v,d-1);
			if (c!=inf) return c;
		}
		int c=query(q->s[1],(w==0)?0:v,d-1);
		if (c!=inf) return c+(1<<(d-1)); else return inf;
	}
}
void solve(int u,int f,node* p,node *T) { // p without this tree *T without path
	rt[u]=cur++; rt[u]->insert(sz[u]);
	ts.insert(sz[u]);
	for (auto v:e[u]) if (v!=f) {
		if (2*sz[v]>sz[u]) { // big
			node *q=p;
			rep(j,l[u]+1,l[v]) q=modify(q,sz[id[j]],1);
			rep(j,r[v]+1,r[u]+1) q=modify(q,sz[id[j]],1);
			node *r=T; r=modify(r,sz[v],-1);
			solve(v,u,q,r);
		} else {
			node *q=T;
			rep(j,l[v],r[v]+1) q=modify(q,sz[id[j]],-1);
			node *r=T; r=modify(r,sz[v],-1);
			solve(v,u,q,r);
		}
	}
	ts.erase(sz[u]);
	vector<PII> sv;
	if (sz[u]!=n) sv.pb(mp(n-sz[u],-1));
	for (auto v:e[u]) if (v!=f) sv.pb(mp(sz[v],v));
	int l=-1,r=n-1;
	while (l+1<r) {
		int md=(l+r)>>1;
		PII c(0,0); int cv=0;
		for (auto r:sv) {
			if (r.fi>md) {
				c=r; cv++;
			}
		}
		if (cv>1) {
			l=md; continue;
		}
		if (cv==0) {
			r=md; continue;
		}
		int vs=1<<30;
		if (c.se!=-1) {
			auto it=rt[c.se]->lower_bound(c.fi-md);
			if (it!=rt[c.se]->end()) vs=*it;
		} else {
			auto it=ts.lower_bound(c.fi-md+sz[u]);
			if (it!=ts.end()) vs=min(vs,(*it)-sz[u]);
			vs=min(vs,query(p,c.fi-md,LOGN));
		}
		bool val=0;
		for (auto r:sv) if (r.fi+vs<=md) val=1;
		if (val) r=md; else l=md;
	}
	ret[u]=r;
	for (auto v:e[u]) if (v!=f) {
		rt[u]=merge(rt[u],rt[v]);
	}
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
		if (u==0||v==0) R=u+v;
	}
	dfs(R,0);
	node *p=qcur++,*rt=qcur++;
	rep(i,0,LOGN) {
		node *q=qcur++;
		q->s[0]=q->s[1]=p;
		p=q;
	}
	Tot=qcur++; *rt=*p; *Tot=*rt;
	rep(i,1,n+1) {
		Tot=modify(Tot,sz[i],1);
	}
	node *r=Tot; r=modify(r,sz[R],-1);
	solve(R,0,rt,r);
	rep(i,1,n+1) printf("%d\n",ret[i]);
}