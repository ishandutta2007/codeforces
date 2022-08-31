#include <bits/stdc++.h>
using namespace std;

const int N=101000;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
typedef vector<int> VI;

int cnt[N],cnt2[N],dfn[N];
VI rt,son[N],tree,nontree,ret;
vector<pair<int,int>> e[N];
pair<int,int> E[N],par[N];
int n,m,u,v,tot;
void dfs(int u) {
	dfn[u]=++tot;
	for (auto p:e[u]) {
		int v=p.fi,id=p.se;
		if (!dfn[v]) {
			dfs(v);
			son[u].pb(v);
			par[v]=mp(u,id);
			tree.pb(id);
		} else if (dfn[u]<dfn[v]) {
			cnt[u]--; cnt[v]++;
			nontree.pb(id);
		}
	}
}
void dfs2(int u) {
	for (auto v:son[u]) {
		dfs2(v);
		cnt[u]+=cnt[v];
	}
	cnt2[u]=cnt[u]>=2;
}
void dfs3(int u) {
	for (auto v:son[u]) {
		cnt2[v]+=cnt2[u];
		dfs3(v);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		E[i]=mp(u,v);
		e[u].pb(mp(v,i));
		e[v].pb(mp(u,i));
	}
	rep(i,1,n+1) if (!dfn[i]) {
		dfs(i); rt.pb(i);
	}
//	rep(i,1,n+1) printf("%d ",cnt[i]); puts("");
	for (auto u:rt) dfs2(u);
	for (auto u:rt) dfs3(u);
	for (auto p:nontree) {
		int u=E[p].fi,v=E[p].se;
		if (dfn[v]<dfn[u]) swap(u,v);
		if (cnt2[v]-cnt2[u]==0) {
			ret.pb(p);
			while (v!=u) {
				ret.pb(par[v].se);
				v=par[v].fi;
			}
		}
	}
	sort(ret.begin(),ret.end());
	printf("%d\n",(int)ret.size());
	for (auto p:ret) printf("%d ",p+1);
	puts("");
}