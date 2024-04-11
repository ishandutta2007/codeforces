#include <bits/stdc++.h>
using namespace std;
#define N 10005
#define M 1000005
#define pb push_back
mt19937 rand1(time(0));
int n,m,B,fa[N],vs[N],st[N],q[N];vector<int> e[N];
int tp;struct Node {int u,v;}ans[M];
void dfs1(int u,int f)
{fa[u]=f;for(auto v:e[u]) if(v!=f) dfs1(v,u);}
void dfs2(int u,int f)
{
	if(vs[u]==1) return;st[++st[0]]=u;
	for(auto v:e[u]) if(v!=f) dfs2(v,u);
}
bool dfs3(int u,int f)
{
	if(vs[u]==1) return 0;int cnt=0;
	for(auto v:e[u]) if(v!=f && dfs3(v,u)) ++cnt;
	if(cnt>1) vs[u]=2;return cnt || vs[u];
}
void dfs4(int u,int f,int x)
{
	if(!u || vs[u]) return;ans[++tp]=(Node) {u,x};
	for(auto v:e[u]) if(v!=f) dfs4(v,u,x);
}
void dfs5(int u,int f,int x)
{
	if(vs[u]==1) return;
	if(vs[u]) x=u,vs[u]=1,st[++st[0]]=u,dfs4(f,0,u);
	else if(x!=f) ans[++tp]=(Node) {u,x};
	for(auto v:e[u]) if(v!=f) dfs5(v,u,x);
}
void slv()
{
	q[0]=2;q[1]=1;q[++q[1]]=1;
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];st[0]=0;dfs2(u,0);
		if(st[0]<5) continue;shuffle(st+2,st+st[0]+1,rand1);
		B=sqrt(st[0]);for(int i=1;i<=B;++i) vs[st[i]]=2;
		st[0]=0;dfs3(u,0);dfs5(u,0,0);
		for(int i=1;i<=st[0];++i) for(int j=1;j<i;++j)
			if(st[i]!=fa[st[j]] && st[j]!=fa[st[i]])
				ans[++tp]=(Node) {st[i],st[j]};
		for(int i=1;i<=st[0];++i) for(auto j:e[st[i]])
			if(st[i]==fa[j] && !vs[j]) q[++q[1]]=j;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<n;++i)
		scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);
	dfs1(1,0);slv();printf("%d\n",tp);
	for(int i=1;i<=tp;++i)
		printf("%d %d\n",ans[i].u,ans[i].v);return 0;
}