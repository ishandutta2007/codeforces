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

const int N=101000;
VI cand,vec,v0,v1,ret;
vector<PII> e[N];
int col[N],vis[N],x[N],y[N],cv[N],n,m,ans;
char s[1010];
void dfs(int u) {
	vis[u]=1; vec.pb(u);
	for (auto p:e[u]) {
		int v=p.fi;
		if (vis[v]) continue;
		cv[v]=cv[u]^p.se;
		dfs(v);
	}
}
void solve() {
	rep(i,0,m) col[i]^=1;
	rep(i,1,n+1) vis[i]=0,e[i].clear();
	rep(i,0,m) {
		e[x[i]].pb(mp(y[i],col[i]));
		e[y[i]].pb(mp(x[i],col[i]));
	}
	cand.clear();
	rep(i,1,n+1) if (!vis[i]) {
		cv[i]=0;
		vec.clear();
		dfs(i);
		v0.clear(); v1.clear();
		for (auto v:vec) if (cv[v]) v1.pb(v); else v0.pb(v);
		if (SZ(v0)<SZ(v1)) {
			for (auto v:v0) cand.pb(v);
		} else {
			for (auto v:v1) cand.pb(v);
		}
	}
	bool val=1;
	rep(i,0,m) if ((cv[x[i]]^cv[y[i]])!=col[i]) val=0;
	if (val==0) return;
	else if (ans==-1||SZ(ret)>SZ(cand)) {
		ans=0;
		ret=cand;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",x+i,y+i);
		scanf("%s",s);
		col[i]=s[0]=='B';
	}
	ans=-1;
	solve();
	solve();
	if (ans==-1) {
		puts("-1");
	} else {
		printf("%d\n",SZ(ret));
		for (auto p:ret) printf("%d ",p);
	}
}