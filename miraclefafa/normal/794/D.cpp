#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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

// test3
const int N=301000;
ll myrand() {
	return ((ll)rand()<<48)+((ll)rand()<<32)+((ll)rand()<<16)+rand(); //+((ll)rand()<<56)+((ll)rand()<<40)+((ll)rand()<<24)+(rand()<<8);
}
set<int> e[N];
int n,m,u,v,id[N],f[N],dep[N],t;
PII E[N];
map<ll,int> hs;
ll lev[N],d[N];
void dfs(int u,int f,int d) {
	dep[u]=d;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u,d+1);
	}
}
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
int main() {
	srand(time(0));
	scanf("%d%d",&n,&m); lev[0]=1;
	rep(i,1,n+1) lev[i]=lev[i-1]*13331;
	rep(i,1,n+1) d[i]=lev[i];
	rep(i,0,m) {
		scanf("%d%d",&u,&v); E[i]=mp(u,v);
		d[u]+=lev[v]; d[v]+=lev[u];
	}
	rep(i,1,n+1) {
		if (!hs.count(d[i])) hs[d[i]]=t++;
		id[i]=hs[d[i]];
	}
	rep(i,0,t) f[i]=i;
	rep(i,0,m) {
		u=id[E[i].fi],v=id[E[i].se];
		if (u==v) continue;
		if (e[u].count(v)||e[v].count(u)) continue;
		if (find(u)==find(v)) {
			puts("NO"); return 0;
		}
		f[find(u)]=find(v);
		e[u].insert(v); e[v].insert(u);
	}
	rep(i,0,t) if (SZ(e[i])>2) {
		puts("NO"); return 0;
	}
	rep(i,0,t) if (SZ(e[i])<2) {
		dfs(i,-1,1);
		puts("YES");
		rep(j,1,n+1) printf("%d ",dep[id[j]]); puts("");
		return 0;
	}
}