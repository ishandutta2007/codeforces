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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
int l[N],r[N],deg[N],val[N],rr[N],tot,q,ty[N],n,p[N];
VI e[N];
void dfs(int u) {
	l[u]=++tot;
	for (auto v:e[u]) {
		dfs(v);
	}
	r[u]=tot;
}

struct node {
	ll fg,dg,sm;
}nd[N*4];
void setc(int p,ll c) {
	nd[p].fg=nd[p].fg*c%mod;
	nd[p].sm=nd[p].sm*c%mod;
	nd[p].dg=nd[p].dg*c%mod;
}
void push(int p) {
	if (nd[p].fg!=1) {
		setc(p+p,nd[p].fg);
		setc(p+p+1,nd[p].fg);
		nd[p].fg=1;
	}
}
void mul(int p,int l,int r,int tl,int tr,ll c) {
	if (l==tl&&r==tr) {
		setc(p,c);
	} else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) mul(p+p,l,md,tl,tr,c);
		else if (tl>md) mul(p+p+1,md+1,r,tl,tr,c);
		else mul(p+p,l,md,tl,md,c),mul(p+p+1,md+1,r,md+1,tr,c);
		nd[p].dg=(nd[p+p].dg+nd[p+p+1].dg)%mod;
		nd[p].sm=(nd[p+p].sm+nd[p+p+1].sm)%mod;
	}
}
void add(int p,int l,int r,int x,ll c,ll v) {
	if (l==r) {
		assert(nd[p].dg==0);
		nd[p].dg=(nd[p].dg+c)%mod;
		nd[p].sm=(nd[p].sm+c*v)%mod;
	} else {
		push(p);
		int md=(l+r)>>1;
		if (x<=md) add(p+p,l,md,x,c,v);
		else if (x>md) add(p+p+1,md+1,r,x,c,v);
		nd[p].dg=(nd[p+p].dg+nd[p+p+1].dg)%mod;
		nd[p].sm=(nd[p+p].sm+nd[p+p+1].sm)%mod;
	}
}
ll queryd(int p,int l,int r,int x) {
	if (l==r) {
		return nd[p].dg;
	} else {
		push(p);
		int md=(l+r)>>1;
		if (x<=md) return queryd(p+p,l,md,x);
		else return queryd(p+p+1,md+1,r,x);		
	}
}
ll query(int p,int l,int r,int tl,int tr) {
//	printf("Q %d %d %d %d\n",l,r,tl,tr);
	if (l==tl&&r==tr) {
		return nd[p].sm;
	} else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return (query(p+p,l,md,tl,md)+query(p+p+1,md+1,r,md+1,tr))%mod;
	}
}
int main() {
	scanf("%d",val+1);
	scanf("%d",&q);
	n=1;
	rep(i,0,q) {
		scanf("%d",ty+i);
		if (ty[i]==1) {
			n++; rr[i]=n;
			scanf("%d%d",p+n,val+n);
			e[p[n]].pb(n);
		} else {
			scanf("%d",rr+i);
		}
	}
	dfs(1);
	rep(i,1,n+1) deg[i]=1;
	add(1,1,n,1,1,val[1]);
//	add(1)
	rep(i,0,q) {
		//printf("%lld\n",nd[1].sm);
		if (ty[i]==1) {
			int u=p[rr[i]],v=rr[i];
		//	printf("mul %d %d %lld\n",l[u],r[u],1+powmod(deg[u],mod-2));
			mul(1,1,n,l[u],r[u],1+powmod(deg[u],mod-2));
			deg[u]++;
			ll pd=queryd(1,1,n,l[u]);
//			printf("add %d %lld %d\n",l[v],pd,val[v]);
			add(1,1,n,l[v],pd,val[v]);
		} else {
			int u=p[rr[i]],v=rr[i];
			ll ret=query(1,1,n,l[v],r[v]);
			if (u) ret=ret*powmod(queryd(1,1,n,l[u]),mod-2)%mod;
			printf("%lld\n",ret);
		}
	}
}