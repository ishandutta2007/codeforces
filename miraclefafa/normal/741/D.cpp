#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
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

const int N=500100,inf=0xe0e0e0e0;
VI s[N];
int Hs[(1<<22)+10],tt;
int n,l[N],r[N],tot,id[N],ret[N],st[N],p;
int Qt[N],Q[N][28],dep[N],sz[N],ms[N],mv[N];
char c;
void upd(int &a,int b) { if (a<b) a=b;}
void dfs(int u) {
	sz[u]=Qt[u]; ms[u]=-1;
	for (auto v:s[u]) {
		dep[v]=dep[u]+1;
		dfs(v); sz[u]+=sz[v];
		if (ms[u]==-1||sz[ms[u]]<sz[v]) ms[u]=v;
	}
}
void solve(int u) {
	id[l[u]=++tot]=u;
	for (auto v:s[u]) if (v!=ms[u]) {
		solve(v);
		rep(j,l[v],r[v]+1) mv[Q[id[j]][0]]=inf;
		ret[u]=max(ret[u],ret[v]);
	}
	if (ms[u]>0) {
		solve(ms[u]);
		ret[u]=max(ret[u],ret[ms[u]]);
	}
	r[u]=tot;
	int tmp=0;
	for (auto v:s[u]) if (v!=ms[u]) {
		rep(j,l[v],r[v]+1) rep(k,0,Qt[id[j]]) tmp=max(tmp,mv[Q[id[j]][k]]+dep[id[j]]);
		rep(j,l[v],r[v]+1) upd(mv[Q[id[j]][0]],dep[id[j]]);
	}
	rep(k,0,Qt[u]) tmp=max(tmp,mv[Q[u][k]]+dep[u]);
	upd(mv[Q[u][0]],dep[u]);
	ret[u]=max(ret[u],tmp-2*dep[u]);
} 
int main() {
	scanf("%d",&n);
	Hs[st[1]]=++tt;
	rep(i,2,n+1) {
		scanf("%d %c",&p,&c);
		st[i]=st[p]^(1<<(c-'a'));
		s[p].pb(i);
		if (Hs[st[i]]==0) Hs[st[i]]=++tt;
	}
	rep(i,1,n+1) {
		Q[i][Qt[i]++]=Hs[st[i]];
		rep(j,0,22) if (Hs[st[i]^(1<<j)]) Q[i][Qt[i]++]=Hs[st[i]^(1<<j)];
	}
	memset(mv,0xe0,sizeof(mv));
	dfs(1);
	solve(1);
	rep(i,1,n+1) printf("%d ",ret[i]);
	puts("");
}