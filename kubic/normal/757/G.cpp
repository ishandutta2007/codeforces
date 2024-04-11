#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define M 12000005
#define LIM 1000005
#define ll long long
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
#define set(a,vl) memset(a,vl,sizeof(a))
const int INF=1e9;char *P1,*P2,buf[LIM];
int n,m,mn,cntV,cntE,a[N],sz[N];bool vs[N];
struct Edge {int u,v,w,id;}G;vector<Edge> e[N],e1[N];
int rt1;ll ans,w[25][N];bool d[25][N];struct Point {int dep,ch[2];Edge e;}pt[N];
int cntS,rt[N];struct Seg {int w,vl1[2],ch[2];ll vl2[2];}sg[M];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
int rd1() {int x=rd();return x^(ans&(1<<30)-1);}
void dfs1(int u,int f)
{
	int lst=u,t;
	for(auto i:e1[u]) if(i.v!=f)
	{
		dfs1(i.v,u);t=++cntV;++cntE;
		e[lst].pb((Edge) {lst,t,0,cntE});e[t].pb((Edge) {t,lst,0,cntE});lst=t;
		e[t].pb((Edge) {t,i.v,i.w,i.id});e[i.v].pb((Edge) {i.v,t,i.w,i.id});
	}
}
void dfs2(int u,int f,int x)
{
	int t=0;sz[u]=1;
	for(auto i:e[u]) if(i.v!=f && !vs[i.id])
	{dfs2(i.v,u,x);sz[u]+=sz[i.v];t=max(sz[i.v],x-sz[i.v]);if(t<mn) mn=t,G=i;}
}
int build(int u,int x)
{
	if(x==1) return 0;int t,u1,v1;mn=INF;dfs2(u,0,x);t=G.id;
	vs[t]=1;pt[t].e=G;u1=G.u;v1=G.v;dfs2(u1,0,x);dfs2(v1,0,x);
	pt[t].ch[0]=build(u1,sz[u1]);pt[t].ch[1]=build(v1,sz[v1]);return t;
}
void dfs3(int u,int f,int x,bool fl)
{
	for(auto i:e[u]) if(i.v!=f && !vs[i.id])
		w[x][i.v]=w[x][u]+i.w,dfs3(i.v,u,x,fl);d[x][u]=fl;
}
void dfs4(int u)
{
	if(!u) return;vs[pt[u].e.id]=1;
	dfs3(pt[u].e.u,0,pt[u].dep,0);dfs3(pt[u].e.v,0,pt[u].dep,1);
	pt[pt[u].ch[0]].dep=pt[u].dep+1;dfs4(pt[u].ch[0]);
	pt[pt[u].ch[1]].dep=pt[u].dep+1;dfs4(pt[u].ch[1]);
}
void upd(int p,int &p1,int u,int dep,int vl)
{
	if(!p) return;sg[p1=++cntS]=sg[p];bool fl=d[dep][u];
	sg[p1].vl1[fl]+=vl;sg[p1].vl2[fl]+=w[dep][u]*vl;
	upd(sg[p].ch[fl],sg[p1].ch[fl],u,dep+1,vl);
}
ll qry(int p,int u,int dep)
{
	if(!p) return 0;ll res;bool fl=d[dep][u];res=qry(sg[p].ch[fl],u,dep+1);
	return res+(w[dep][u]+sg[p].w)*sg[p].vl1[!fl]+sg[p].vl2[!fl];
}
int main()
{
	n=rd();m=rd();cntV=n;cntE=n-1;for(int i=1;i<=n;++i) a[i]=rd();
	for(int i=1,u,v,w;i<n;++i)
	{u=rd();v=rd();w=rd();e1[u].pb((Edge) {u,v,w,i});e1[v].pb((Edge) {v,u,w,i});}
	dfs1(1,0);rt1=build(1,cntV);set(vs,0);dfs4(rt1);
	for(int i=1;i<=cntE;++i)
		sg[i].w=pt[i].e.w,sg[i].ch[0]=pt[i].ch[0],sg[i].ch[1]=pt[i].ch[1];
	cntS=cntE;rt[0]=rt1;for(int i=1;i<=n;++i) upd(rt[i-1],rt[i],a[i],0,1);
	for(int i=1,op,l,r,u;i<=m;++i)
	{
		op=rd();
		if(op==1)
		{
			l=rd1();r=rd1();u=rd1();
			printf("%lld\n",ans=qry(rt[r],u,0)-qry(rt[l-1],u,0));
		}
		if(op==2)
		{
			u=rd1();upd(rt[u],rt[u],a[u],0,-1);
			swap(a[u],a[u+1]);upd(rt[u],rt[u],a[u],0,1);
		}
	}return 0;
}