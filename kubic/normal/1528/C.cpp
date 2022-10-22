#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define pb push_back 
int T,n,m,ans,L[N],R[N];vector<int> e1[N],e2[N];
struct Node
{
	int u;
	bool operator < (Node t) const {return L[u]<L[t.u];}
};set<Node> z;
int qry1(int u)
{
	int t;set<Node>::iterator it=z.upper_bound((Node) {u});
	if(it==z.begin()) return 0;t=(--it)->u;
	return L[u]>=L[t] && L[u]<=R[t]?t:0;
}
int qry2(int u)
{
	int t;set<Node>::iterator it=z.lower_bound((Node) {u});
	if(it==z.end()) return 0;t=it->u;
	return L[t]>=L[u] && L[t]<=R[u]?t:0; 
}
void dfs1(int u)
{L[u]=++L[0];for(auto v:e2[u]) dfs1(v);R[u]=L[0];}
void dfs2(int u)
{
	if(u==1) z.insert((Node) {1});int t=qry1(u);
	if(t) z.insert((Node) {u}),z.erase((Node) {t});
	else if(!(qry2(u))) z.insert((Node) {u});
	ans=max(ans,(int)z.size());for(auto v:e1[u]) dfs2(v);
	z.erase((Node) {u});if(t) z.insert((Node) {t});
}
void slv()
{
	scanf("%d",&n);ans=L[0]=0;z.clear();
	for(int i=1;i<=n;++i) e1[i].clear(),e2[i].clear();
	for(int i=2,f;i<=n;++i) scanf("%d",&f),e1[f].pb(i);
	for(int i=2,f;i<=n;++i) scanf("%d",&f),e2[f].pb(i);
	dfs1(1);dfs2(1);printf("%d\n",ans);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}