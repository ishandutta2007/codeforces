#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define pb push_back
const int lim=(1<<30)-1;
int n,m,ans,rt,U[N],V[N],w1[N],w2[N];vector<int> e[N];
struct Node
{
	int x,y,id;
	bool operator < (Node t) const {return x==t.x?y<t.y:x<t.x;}
}a[N];vector<Node> z;map<int,bool> w;map<Node,int> id;
struct Point {int fa,dep,sz,hv,tp;}pt[N];
int build(int x1,int y1,int x2,int y2,vector<Node> z)
{
	if(!z.size()) return 0;if(z.size()==1) return z[0].id;
	if(x1==x2 && y1==y2)
	{
		int t;Node t1=(Node) {x1,y1,0};
		if(!id[t1]) a[id[t1]=++n]=t1;t=id[t1];
		for(auto i:z) if(t!=i.id) e[t].pb(i.id);return t;
	}int midX=(x1+x2)/2,midY=(y1+y2)/2,rt1,rt2;
	vector<Node> z1,z2,z3;z1.clear();z2.clear();z3.clear();
	for(auto i:z) if(i.x>midX) z1.pb(i);
		else if(i.y>midY) z2.pb(i);else z3.pb(i);
	rt1=build(midX+1,y1,x2,midY,z1);rt2=build(x1,midY+1,midX,y2,z2);
	if(rt1) z3.pb((Node) {midX,y1,rt1});
	if(rt2) z3.pb((Node) {x1,midY,rt2});
	return build(x1,y1,midX,midY,z3);
}
void dfs1(int u,int f)
{
	pt[u].fa=f;pt[u].dep=pt[f].dep+1;pt[u].sz=1;
	for(auto v:e[u])
	{
		dfs1(v,u);pt[u].sz+=pt[v].sz;
		if(pt[v].sz>pt[pt[u].hv].sz) pt[u].hv=v;
	}
}
void dfs2(int u,int f)
{
	pt[u].tp=f;if(pt[u].hv) dfs2(pt[u].hv,f);
	for(auto v:e[u]) if(v!=pt[u].fa && v!=pt[u].hv) dfs2(v,v);
}
void dfs3(int u,int f)
{
	for(auto v:e[u]) dfs3(v,u),w1[u]+=w1[v];
	if(w1[u]) {w[a[u].x+a[u].y]^=1;if(f) w[a[f].x+a[f].y]^=1;}
	else if(w2[u]) {w[a[u].x+a[u].y]^=1;if(f) w[a[u].x+a[u].y-1]^=1;}
}
int LCA(int u,int v)
{
	while(pt[u].tp!=pt[v].tp)
	{
		if(pt[pt[u].tp].dep<pt[pt[v].tp].dep) swap(u,v);
		u=pt[pt[u].tp].fa;
	}if(pt[u].dep<pt[v].dep) swap(u,v);return v;
}
int main()
{
	scanf("%d",&m);a[++n]=(Node) {0,0};id[a[n]]=n; 
	for(int i=1;i<=m;++i)
	{
		Node u,v;scanf("%d %d %d %d",&u.x,&u.y,&v.x,&v.y);
		u.id=0;if(!id[u]) a[id[u]=++n]=u;U[i]=id[u]; 
		v.id=0;if(!id[v]) a[id[v]=++n]=v;V[i]=id[v];
	}for(int i=1;i<=n;++i) z.pb((Node) {a[i].x,a[i].y,i});
	rt=build(0,0,lim,lim,z);dfs1(rt,0);dfs2(rt,rt);
	for(int i=1,u,v,t;i<=m;++i)
		u=U[i],v=V[i],t=LCA(u,v),++w1[u],++w1[v],w1[t]-=2,++w2[t];
	dfs3(rt,0);for(auto i:w) if(i.second) ++ans;
	printf("%d\n",ans);return 0; 
}