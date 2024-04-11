#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define M 500005
#define LIM 1000005
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char buf[LIM],*P1,*P2;
int n,m,dfsT,vl[N],fa[N];bool vs[N];
int cntE,hd[N];struct Edge {int v,w,nxt;}e[M*2];
struct Edge1 {int u,v,w;}a[M];
struct Point {int fa,dep,sz,hv,dfn,tp,s;}pt[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
void addE(int u,int v,int w) {e[++cntE]=(Edge) {v,w,hd[u]};hd[u]=cntE;}
int findRt(int u) {return u==fa[u]?u:fa[u]=findRt(fa[u]);}
void merge(int u,int v,int w)
{
	int tU=findRt(u),tV=findRt(v);if(tU==tV) return;
	addE(u,v,w);addE(v,u,w);fa[tU]=tV;
}
void dfs1(int u,int f)
{
	pt[u].fa=f;pt[u].dep=pt[f].dep+1;pt[u].sz=1;
	for(int i=hd[u],v,w;i;i=e[i].nxt)
	{
		v=e[i].v;w=e[i].w;if(v==f) continue;
		pt[v].s=pt[u].s^w;dfs1(v,u);pt[u].sz+=pt[v].sz;
		if(pt[v].sz>pt[pt[u].hv].sz) pt[u].hv=v;
	}
}
void dfs2(int u,int f)
{
	pt[u].dfn=++dfsT;pt[u].tp=f;if(pt[u].hv) dfs2(pt[u].hv,f);
	for(int i=hd[u],v,w;i;i=e[i].nxt)
	{v=e[i].v;if(v!=pt[u].fa && v!=pt[u].hv) dfs2(v,v);}
}
int LCA(int u,int v)
{
	while(pt[u].tp!=pt[v].tp)
	{
		if(pt[pt[u].tp].dep<pt[pt[v].tp].dep) swap(u,v);
		u=pt[pt[u].tp].fa;
	}if(pt[u].dep<pt[v].dep) swap(u,v);return v;
}
void upd(int x,int w) {for(;x<=n;x+=x&-x) vl[x]+=w;}
int qSm(int x) {int res=0;for(;x;x-=x&-x) res+=vl[x];return res;}
void updR(int u,int v)
{
	int t=LCA(u,v);
	for(int i=u;i!=t;i=pt[i].fa) upd(pt[i].dfn,1),upd(pt[i].dfn+pt[i].sz,-1);
	for(int i=v;i!=t;i=pt[i].fa) upd(pt[i].dfn,1),upd(pt[i].dfn+pt[i].sz,-1);
}
int qSmR(int u,int v)
{int t=LCA(u,v);return qSm(pt[u].dfn)+qSm(pt[v].dfn)-qSm(pt[t].dfn)*2;}
void slv(int u,int v,int w)
{
	if(v==pt[u].fa || u==pt[v].fa) {puts("Yes");return;}
	if(pt[u].s^pt[v].s^w!=1 || qSmR(u,v)) {puts("No");return;}
	updR(u,v);puts("Yes");
}
int main()
{
	n=rd();m=rd();for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1,u,v,w;i<=m;++i)
		u=rd(),v=rd(),w=rd(),a[i]=(Edge1) {u,v,w},merge(u,v,w);
	for(int i=1;i<=n;++i) if(!pt[i].dfn) dfs1(i,0),dfs2(i,i);
	for(int i=1;i<=m;++i) slv(a[i].u,a[i].v,a[i].w);return 0;
}