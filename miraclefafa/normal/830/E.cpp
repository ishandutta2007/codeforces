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

const int N=101000;
int u,v,deg[N],f[N],val[N],n,m,_,vis[N];
VI e[N],br[10],vec;
PII E[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
void dfs(int u) {
	vec.pb(u); vis[u]=1;
	for (auto v:e[u]) if (!vis[v]) {
		dfs(v);
	}
}

void dfs(int u,int f,int id) {
	br[id].pb(u);
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u,id);
	}
}
bool solve() {
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		E[i]=mp(u,v);
		e[u].pb(v); e[v].pb(u);
		deg[u]++; deg[v]++;
	}
	rep(i,0,m) {
		u=E[i].fi; v=E[i].se;
		if (find(u)==find(v)) {
			puts("YES");
			rep(i,1,n+1) if (find(i)==find(u)) printf("%d ",1); else printf("%d ",0);
			puts("");
			return 1;
		} else {
			f[find(u)]=find(v);
		}
	}
	rep(u,1,n+1) if (!vis[u]) {
		vec.clear();
		dfs(u);
		int leaf=0;
		for (auto v:vec) if (deg[v]==1) leaf++;
		if (leaf>=4) {
			puts("YES");
			rep(i,1,n+1) {
				if (find(i)==find(u)) printf("%d ",deg[i]==1?1:2); else printf("%d ",0);
			}
			puts("");
			return 1;
		}
		if (leaf<=2) {
			continue;
		}
		// hard case
		int rt=0;
		for (auto v:vec) if (deg[v]==3) {
			rt=v; break;
		}
		rep(i,0,3) br[i].clear();
		rep(i,0,SZ(e[rt])) {
			dfs(e[rt][i],rt,i);
		}
		if (SZ(br[0])<SZ(br[1])) swap(br[0],br[1]);
		if (SZ(br[0])<SZ(br[2])) swap(br[0],br[2]);
		if (SZ(br[1])<SZ(br[2])) swap(br[1],br[2]);
		assert(SZ(br[0])>=1&&SZ(br[1])>=1&&SZ(br[2])>=1);
		if (SZ(br[1])==1) {
			continue;
		}
		if (SZ(br[2])>=2) {
			val[rt]=3;
			rep(i,0,2) val[br[0][i]]=2-i;
			rep(i,0,2) val[br[1][i]]=2-i;
			rep(i,0,2) val[br[2][i]]=2-i;
			puts("YES");
			rep(i,1,n+1) printf("%d ",val[i]); puts("");
			return 1;
		}
		if (SZ(br[1])>=3) {
			val[rt]=4;
			rep(i,0,3) val[br[0][i]]=3-i;
			rep(i,0,3) val[br[1][i]]=3-i;
			val[br[2][0]]=2;
			puts("YES");
			rep(i,1,n+1) printf("%d ",val[i]); puts("");
			return 1;
		}
		if (SZ(br[0])>=5) {
			val[rt]=6;
			rep(i,0,5) val[br[0][i]]=5-i;
			rep(i,0,2) val[br[1][i]]=4-2*i;
			val[br[2][0]]=3;
			puts("YES");
			rep(i,1,n+1) printf("%d ",val[i]); puts("");
			return 1;		
		}
	}
	return 0;
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&m);
		rep(i,1,n+1) e[i].clear(),f[i]=i,deg[i]=0,val[i]=0,vis[i]=0;
		if (!solve()) puts("NO");
	}
}