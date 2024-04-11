#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define mid (((l)+(r))>>1)
#define set(a,v) memset(a,v,sizeof(a))
int n,m;
int cntE,hd[N];struct Edge {int v,nxt;}e[N<<1];
int rtS,cntS;struct Seg {int lc,rc,v,tg;}sg[N<<2];
int dfsT;struct Point {int fa,d,sz,hv,tp,id;}pt[N];
void swp(int &x,int &y) {int t=x;x=y;y=t;}
void addE(int u,int v) {e[++cntE]=(Edge) {v,hd[u]};hd[u]=cntE;}
void f(int p,int v) {sg[p].v=sg[p].tg=v;}
void pd(int p)
{
	if(sg[p].tg)
	{
		if(!sg[p].lc) sg[p].lc=++cntS;f(sg[p].lc,sg[p].tg);
		if(!sg[p].rc) sg[p].rc=++cntS;f(sg[p].rc,sg[p].tg);
		sg[p].tg=0;
	}
}
void upd(int &p,int l,int r,int qL,int qR,int v)
{
	if(!p) p=++cntS;if(l>=qL && r<=qR) {f(p,v);return;}pd(p);
	if(qL<=mid) upd(sg[p].lc,l,mid,qL,qR,v);if(qR>mid) upd(sg[p].rc,mid+1,r,qL,qR,v);
}
int q(int p,int l,int r,int x)
{
	if(!p || l==r) return sg[p].v;pd(p);
	if(x<=mid) return q(sg[p].lc,l,mid,x);else return q(sg[p].rc,mid+1,r,x);
}
void dfs1(int u,int f)
{
	pt[u].fa=f;pt[u].d=pt[f].d+1;pt[u].sz=1;
	for(int i=hd[u],v;~i;i=e[i].nxt)
	{
		v=e[i].v;if(v==f) continue;dfs1(v,u);
		pt[u].sz+=pt[v].sz;if(pt[v].sz>pt[pt[u].hv].sz) pt[u].hv=v;
	}
}
void dfs2(int u,int f)
{
	pt[u].tp=f;pt[u].id=++dfsT;if(!pt[u].hv) return;dfs2(pt[u].hv,f);
	for(int i=hd[u],v;~i;i=e[i].nxt) {v=e[i].v;if(v!=pt[u].fa && v!=pt[u].hv) dfs2(v,v);}
}
void updTr(int u,int _v) {upd(rtS,1,n,pt[u].id,pt[u].id+pt[u].sz-1,_v);}
void updRng(int u,int v,int _v)
{
	while(pt[u].tp!=pt[v].tp)
	{
		if(pt[pt[u].tp].d<pt[pt[v].tp].d) swp(u,v);
		upd(rtS,1,n,pt[pt[u].tp].id,pt[u].id,_v);u=pt[pt[u].tp].fa;
	}
	if(pt[u].d<pt[v].d) swp(u,v);upd(rtS,1,n,pt[v].id,pt[u].id,_v);
}
int qPt(int u) {return q(rtS,1,n,pt[u].id);}
int main()
{
	set(hd,-1);scanf("%d",&n);
	for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v),addE(u,v),addE(v,u);
	dfs1(1,0);dfs2(1,1);scanf("%d",&m);
	for(int i=1,F[2];i<=m;++i)
	{
		scanf("%d %d",&F[0],&F[1]);
		if(F[0]==1) updTr(F[1],1);
		else if(F[0]==2) updRng(1,F[1],-1);
		else if(F[0]==3) printf("%d\n",qPt(F[1])==1);
	}
}