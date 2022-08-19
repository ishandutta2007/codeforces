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

const int N=201000;

VI vec,chain,e[N];
vector<VI> ret,vc;
int q[N],f[N],vis[N],sz[N],ms[N];
int deg[N];
int n,u,v;
VI find(int u) {
	int t=1;q[0]=u;f[u]=-1;
	VI res;
	rep(i,0,t) {
		u=q[i];
		rep(j,0,e[u].size()) {
			int v=e[u][j];
			if (v!=f[u]) f[q[t++]=v]=u;
		}
		ms[q[i]]=0;
		sz[q[i]]=1;
	}
	for (int i=t-1;i>=0;i--) {
		ms[q[i]]=max(ms[q[i]],t-sz[q[i]]);
		if (ms[q[i]]*2<=t) res.pb(q[i]);
		sz[f[q[i]]]+=sz[q[i]];
		ms[f[q[i]]]=max(ms[f[q[i]]],sz[q[i]]);
	}
	return res;
}

void dfs(int u,int f) {
	vec.pb(u);
	for (auto v:e[u]) if (v!=f) dfs(v,u);
}
void oper(int u,int v,int w) {
	ret.pb(VI{u,v,w});
}
void gao(int u,int f) {
	vec.clear(); chain.clear();
	dfs(u,f);
	chain.clear();
	for (auto v:vec) deg[v]=SZ(e[v]);
	int t=0;
	for (auto v:vec) if (deg[v]==1) {
		q[t++]=v;
	}
	chain.pb(f);
	vis[f]=1;
	int prev=f,prel=u;
	rep(i,0,t) {
		chain.pb(q[i]);
		vis[q[i]]=1;
		oper(prev,prel,q[i]);
		--deg[prel];
		if (deg[prel]==1) {
			q[t++]=prel;
			assert(!vis[prel]);
		}
		prev=q[i]; prel=-1;
		for (auto v:e[q[i]]) {
			if (vis[v]==0) prel=v;
		}
	}
}
int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	auto r=find(1);
	if (SZ(r)==1) {
		u=r[0];
		for (auto v:e[u]) {
			gao(v,u);
			vc.pb(chain);
		}
	} else {
		u=r[0]; v=r[1];
		for (auto w:e[u]) if (w!=v) {
			gao(w,u);
			vc.pb(chain);
		}
		for (auto w:e[v]) if (w!=u) {
			gao(w,v);
			vc.pb(chain);
		}
	}
	for (auto p:vc) {
		chain=p;
		if (SZ(chain)>3) {
			int mr=chain[SZ(chain)-2];
			per(i,0,SZ(chain)-3) {
				oper(chain[i],chain[i+1],mr);
			}
		}
	}
	printf("%d\n",SZ(ret));
	for (auto p:ret) {
		printf("%d %d %d\n",p[0],p[1],p[2]);
	}
}