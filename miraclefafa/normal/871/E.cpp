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

const int N=30100;
int rtp[N],rt[N],f[N],d[210][N],ord[N];
VI prt;
int n,k;
map<VI,int> hs;
VI vec[N],e[N];
set<PII> E;
set<int> ins;
void fuck(bool op) {
	if (op==0) {
		puts("-1");
		exit(0);
	}
}
int find(int u) { return f[u]==u?u:f[u]=find(f[u]); }
void add(int u,int v) {
	if (u>v) swap(u,v);
	if (E.count(mp(u+1,v+1))) return;
	fuck(find(u)!=find(v));
	f[find(u)]=find(v);
	E.insert(mp(u+1,v+1));
	e[u].pb(v);
	e[v].pb(u);
}
void dfs(int u,int f,int dep,int id) {
	fuck(d[id][u]==dep);
	for (auto v:e[u]) if (v!=f) dfs(v,u,dep+1,id);
}
int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,n) rtp[i]=-1;
	rep(i,0,n) f[i]=i;
	rep(i,0,k) {
		VI r;
		rep(j,0,n) {
			scanf("%d",&d[i][j]);
			if (d[i][j]==0) r.pb(j);
		}
		fuck(SZ(r)==1);
		rt[i]=r[0];
		if (rtp[rt[i]]==-1) rtp[rt[i]]=i,prt.pb(rt[i]);
		else {
			rep(j,0,n) fuck(d[i][j]==d[rtp[rt[i]]][j]);
		}
	}
	int u=prt[0];
	ins.insert(u);
	for (auto v:prt) {
		if (v==u) continue;
		int idu=rtp[u],idv=rtp[v];
		fuck(d[idu][v]==d[idv][u]);
		int dis=d[idu][v];
		rep(i,0,dis+1) vec[i].clear();
		rep(i,0,n) if (d[idu][i]+d[idv][i]==dis) {
			vec[d[idu][i]].pb(i);
		}
		rep(i,0,dis+1) fuck(SZ(vec[i])==1);
		rep(i,1,dis+1) {
			int p=vec[i-1][0],q=vec[i][0];
			add(p,q);
			ins.insert(p);
			ins.insert(q);
		}
	}
	for (auto p:ins) {
		VI it;
		rep(j,0,k) it.pb(d[j][p]);
		hs[it]=p;
	}
	rep(i,0,n) ord[i]=i;
	sort(ord,ord+n,[&](int u,int v){ return d[0][u]<d[0][v]; });
	rep(i,0,n) {
		int p=ord[i];
		if (ins.count(p)) continue;
		VI it,nit;
		rep(j,0,k) {
			fuck(d[j][p]>0);
			it.pb(d[j][p]-1);
			nit.pb(d[j][p]);
		}
		fuck(hs.count(it));
		add(hs[it],p);
		hs[nit]=p;
	}
	rep(i,0,k) dfs(rt[i],-1,0,i);
	for (auto p:E) printf("%d %d\n",p.fi,p.se);
}