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

const int N=601000;
int hs[N][27],cnt[N][27],dep[N],sz[N],ch[N],md,ct,cur,n,u,v;
char op[10];
VI son[N],vec[N];
vector<PII> e[N];
void dfs(int u,int f) {
	dep[u]=dep[f]+1;
	sz[u]=1;
	md=max(md,dep[u]);
	vec[dep[u]].pb(u);
	for (auto p:e[u]) {
		int v=p.fi,w=p.se;
		if (v==f) continue;
		dfs(v,u);
		son[u].pb(v);
		ch[v]=w;
		sz[u]+=sz[v];
		hs[u][w]=v;
		cnt[u][w]++;
	}
}
void dfs1(int u,int c) {
	for (auto p:son[c]) {
		int w=ch[p];
		if (hs[u][w]==0) {
			hs[u][w]=cur++;
		} else ct++;
		cnt[u][w]++;
		dfs1(hs[u][w],p);
	}
}
void dfs2(int u,int c) {
	for (auto p:son[c]) {
		int w=ch[p];
		dfs2(hs[u][w],p);
		--cnt[u][w];
		if (cnt[u][w]==0) hs[u][w]=0;
	}	
}
int gao(int u) {
	if (son[u].empty()) return 0;
	int ms=-1;
	for (auto v:son[u]) {
		if (ms==-1||sz[v]>sz[ms]) {
			ms=v;
		}
	}
	ct=0;
	cur=n+1;
	for (auto v:son[u]) {
		if (v==ms) continue;
		dfs1(ms,v);
	}
	for (auto v:son[u]) {
		if (v==ms) continue;
		dfs2(ms,v);
	}
	rep(i,n+1,cur) {
		rep(j,0,26) assert(cnt[i][j]==0&&hs[i][j]==0);
	}
	return ct;
}
int main() {
	scanf("%d",&n);
	rep(i,2,n+1) {
		scanf("%d%d%s",&u,&v,op);
//		u=i/2, v=i; op[0]=i%2+'a';
		e[u].pb(mp(v,op[0]-'a'));
		e[v].pb(mp(u,op[0]-'a'));
	}
	dfs(1,0);
	int ans=n+1,p=-1;
	rep(i,1,md+1) {
		int ret=n;
		for (auto u:vec[i]) {
			ret-=SZ(son[u]);
			ret-=gao(u);
		}
//		printf("%d %d\n",ret,i);
		if (ret<ans) ans=ret,p=i;
	}
	printf("%d\n%d\n",ans,p);
}