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
bool vis[N],ins[N],mark[N];
vector<PII> ret,e[N];
PII E[N];
int n,m,u,v;
void dfs(int u,int pe) {
	vis[u]=1; ins[u]=1;
	for (auto p:e[u]) {
		int v=p.fi;
		if (!vis[v]) dfs(v,p.se);
	}
	vector<int> ce;
	for (auto p:e[u]) {
		int d=p.se,v=p.fi;
		if (!ins[v]&&!mark[d]) ce.pb(d);
	}
	if (SZ(ce)%2==1) {
		if (pe==-1) ce.pop_back();
		else ce.pb(pe);
	}
	rep(i,0,SZ(ce)/2) {
		ret.pb(mp(ce[2*i],ce[2*i+1]));
		mark[ce[2*i]]=mark[ce[2*i+1]]=1;
	}
	ins[u]=0;
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		e[u].pb(mp(v,i));
		e[v].pb(mp(u,i));
		E[i]=mp(u,v);
	}
	rep(i,1,n+1) if (!vis[i]) dfs(i,-1);
	printf("%d\n",SZ(ret));
	for (auto p:ret) {
		int f=p.fi,g=p.se;
		if (E[f].fi!=E[g].fi&&E[f].fi!=E[g].se) swap(E[f].fi,E[f].se);
		if (E[g].fi!=E[f].fi) swap(E[g].fi,E[g].se);
		printf("%d %d %d\n",E[f].se,E[f].fi,E[g].se);
	}
}