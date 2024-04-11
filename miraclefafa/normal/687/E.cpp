#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <queue>
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

const int N=5010;
int dfn[N],low[N],ins[N],st[N],bel[N],dis[N],vis[N];
int ind,top,n,m,u,v,cnt,maxc;
VI vec[N],e[N],f[N];
queue<int> q;
vector<PII> E;
void tarjan(int u) {
	dfn[u]=low[u]=++ind;
	ins[u]=1;
	st[++top]=u;
	rep(i,0,SZ(e[u])) {
		int v=e[u][i];
		if (!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if (ins[v]) low[u]=min(low[u],low[v]);
	} 
	if (dfn[u]==low[u]) {
		++cnt;
		while (1) {
			bel[st[top]]=cnt;
			vec[cnt].pb(st[top]);
			ins[st[top]]=0;
			if (st[top--]==u) break;
		}
	}
}

void find(int u) {
	rep(i,1,n+1) vis[i]=0,dis[i]=n+1;
	vis[u]=1; q.push(u); dis[u]=0;
	while (!q.empty()) {
		int v=q.front(); q.pop();
		for (auto w:e[v]) if (!vis[w]) {
			vis[w]=1; dis[w]=dis[v]+1;
			q.push(w);
		} 
	}
//	printf("%d\n",u);
//	rep(i,1,n+1) printf("%d %d\n",i,dis[i]);
	rep(i,1,n+1) for (auto v:e[i]) if (v==u) {
		maxc=min(maxc,dis[i]+1);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		E.pb(mp(u,v));
	}
	rep(i,1,n+1) if (!dfn[i]) tarjan(i);
	rep(i,0,m) {
		int u=E[i].fi,v=E[i].se;
		if (bel[u]!=bel[v]) {
			f[bel[u]].pb(bel[v]);
		}
	}
	int ret=n;
	rep(i,1,cnt+1) if (SZ(f[i])==0) {
		if (SZ(vec[i])==1) continue;
		maxc=n;
		for (auto u:vec[i]) find(u);
		ret+=998*maxc+1;
	}
	printf("%d\n",ret);
}