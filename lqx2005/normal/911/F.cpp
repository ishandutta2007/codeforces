#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=200000;
struct E
{
	int to,nxt;
}e[maxn*2+5];
int n,h[maxn+5],ent=0;
int mdep,id,S,T;
int sz[maxn+5],top[maxn+5],pa[maxn+5],son[maxn+5],dep[maxn+5],ans=0;
int v[maxn+5];
vector<int> oa,ob,oc,od;
void add(int u,int v)
{
	ent++;
	e[ent].to=v;
	e[ent].nxt=h[u];
	h[u]=ent;
	return;
}
void Dfs(int u,int fa,int dep)
{
	if(dep>mdep)mdep=dep,id=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa) continue;
		Dfs(v,u,dep+1);
	}
	return;
}
void dfs1(int u,int fa)
{
	dep[u]=dep[fa]+1;
	pa[u]=fa;
	sz[u]=1;
	son[u]=-1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(son[u]==-1||sz[son[u]]<sz[v]) son[u]=v;
	}
	return;
}
void dfs2(int u,int fa)
{
	if(!top[u]) top[u]=u;
	if(son[u]!=-1)
	{
		top[son[u]]=top[u];
		dfs2(son[u],u);
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa||v==son[u]) continue;
		dfs2(v,u);
	}
	return;
}
int Lca(int u,int v)
{
	for(;top[u]!=top[v];)
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=pa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	return u;
}
int Tag(int u,int fa)
{
	if(u==T) v[u]=1;
	int fag=v[u];
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa) continue;
		fag|=Tag(v,u);
	}
	v[u]=fag;
	if(fag) od.push_back(u);
	return fag;
}
int que(int u,int v)
{
	int lca=Lca(u,v);
	return dep[u]+dep[v]-dep[lca]*2;
}
void query(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa) continue;
		query(v,u);
	}
	if(v[u]) return;
	if(que(u,S)>que(u,T)) oa.push_back(u),ob.push_back(S),oc.push_back(u);
	else oa.push_back(u),ob.push_back(T),oc.push_back(u);
	ans+=max(que(u,S),que(u,T));	
	return;
}
signed main()
{
	scanf("%lld",&n);
	int U,V;
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld",&U,&V);
		add(U,V);
		add(V,U);
	}
	mdep=-1;
	Dfs(1,0,0);
	S=id;  
	mdep=-1;
	Dfs(S,0,0);
	T=id;
	dep[0]=-1;
	dfs1(1,0);
	dfs2(1,0);
	Tag(S,0);
	query(S,0);
	ans+=(que(S,T)+1)*que(S,T)/2;
	printf("%lld\n",ans);
	for(int i=0;i<oa.size();i++) printf("%lld %lld %lld\n",oa[i],ob[i],oc[i]);
	for(int i=(int)od.size()-1;i>0;i--) printf("%lld %lld %lld\n",T,od[i],od[i]);
	return 0;
}