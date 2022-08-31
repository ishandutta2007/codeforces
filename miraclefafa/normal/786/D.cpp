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

const int N=40100;
int T,p[N],c[N],dep[N],ch[N],vis[N],st[N],q,ret[N],cp[N];
int n,u,v;
char s[10];

vector<PII> e[N],Q[N];
void dfs(int u,int f) {
	for (auto v:e[u]) if (v.fi!=f) {
		dfs(v.fi,u); p[v.fi]=u; c[v.fi]=v.se;
	}
}
int gao(int u,int v) {
	T++;
	int r=v,tot=0; dep[v]=n;
	int ret=-1;
	while (r!=u) {
		ch[dep[r]]=c[r];
		vis[r]=T;
		cp[r]=1;
		dep[p[r]]=dep[r]-1;
		r=p[r];
		ret++;
	}
	vis[u]=T; cp[u]=1;
	rep(j,1,n+1) if (vis[j]!=T) {
		int top=0,r=j;
		while (vis[r]!=T) st[top++]=r,r=p[r];
		per(i,0,top) {
			int r=st[i];
			dep[r]=dep[p[r]]+1;
			vis[r]=T;
			if (cp[p[r]]!=1) cp[r]=cp[p[r]];
			else if (ch[dep[r]]>c[r]) cp[r]=0;
			else if (ch[dep[r]]==c[r]) cp[r]=1; else cp[r]=2;
			ret+=(cp[r]==0)||(cp[r]==1&&dep[r]<dep[v]);
		}
	}
	return ret;
}
void solve(int u,int f) {
	for (auto v:Q[u]) ret[v.se]=gao(u,v.fi);
	int pr=c[u];
	for (auto v:e[u]) if (v.fi!=f) {
		p[u]=v.fi; c[u]=v.se;
		solve(v.fi,u);
	}
	c[u]=pr; p[u]=f;
}
int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n) {
		scanf("%d%d%s",&u,&v,s);
		e[u].pb(mp(v,s[0])); e[v].pb(mp(u,s[0]));
	}
	dfs(1,0);
	rep(i,0,q) {
		scanf("%d%d",&u,&v);
		Q[u].pb(mp(v,i));
	}
	solve(1,0);
	rep(i,0,q) printf("%d\n",ret[i]);
}