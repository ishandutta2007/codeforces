#include <bits/stdc++.h>
using namespace std;
#define N 105
#define ulll __uint128_t
#define pb push_back
int n,tp,rt,ps,w[N],fa[N];ulll pw[N],z[N],st[N];bool vs[N];
struct Node {int u;ulll w;bool operator < (Node t) const {return w<t.w;}};
vector<int> e[N];priority_queue<Node> q,q1;
int qry(int u,int v)
{int res;printf("? %d %d\n",u,v);fflush(stdout);scanf("%d",&res);return res;}
bool chk(int d,ulll x)
{
	Node t;q1=q;
	for(int i=d;i && !q1.empty();--i) if(q1.top().w>>i&1)
	{
		if(!(x>>i&1)) return 0;t=q1.top();q1.pop();
		if(!q1.empty() && q1.top().w>>i&1) return 0;t.w^=pw[i];q1.push(t);
	}else if(x>>i&1) q1.pop();return q1.empty();
}
void dfs(int u,int f)
{
	Node t;fa[u]=f;for(auto v:e[u]) if(v!=f) dfs(v,u);
	while(!q.empty()) q.pop();for(auto v:e[u]) if(v!=f) q.push((Node) {v,z[v]});
	for(int i=n;i && !q.empty();--i) if(!chk(i,pw[i]-2))
	{
		if(q.top().w>>i&1) {t=q.top();q.pop();t.w^=pw[i];q.push(t);}
		else w[q.top().u]=i,q.pop();z[u]|=pw[i];
	}
}
void dfs1(int u,int f)
{
	if(vs[u]) return;if(fa[u] && !vs[fa[u]] && w[u]>w[ps]) ps=u;
	for(auto v:e[u]) if(v!=f) dfs1(v,u);
}
int main()
{
	scanf("%d",&n);rt=pw[0]=1;for(int i=1;i<=n;++i) pw[i]=pw[i-1]*2;
	for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);dfs(1,0);
	while(1)
	{
		ps=0;dfs1(rt,0);if(!ps) {printf("! %d\n",rt);fflush(stdout);return 0;}
		if(qry(ps,fa[ps])==ps) vs[fa[ps]]=1,rt=ps;else vs[ps]=1,rt=fa[ps];
	}return 0;
}