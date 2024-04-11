#include <bits/stdc++.h>
using namespace std;
#define N 250005
#define pb push_back
#define ll long long
const ll INF=1e18;
int n,st[N],fa[N],fe[N];ll ans[N],dp[N][2];bool vs[N];struct Edge {int v,w;};
vector<Edge> e[N],e1[N];vector<int> vc[N];
int cntP,rt[N],bin[N];struct Point {int w,sz,ch[2];ll vl[2];}pt[N];
int New(ll vl)
{int p=bin[0]?bin[bin[0]--]:++cntP;pt[p]=(Point) {rand(),1,{0,0},{vl,vl}};return p;}
void pu(int p)
{
	int ch[2]={pt[p].ch[0],pt[p].ch[1]};pt[p].sz=pt[ch[0]].sz+pt[ch[1]].sz+1;
	pt[p].vl[1]=pt[ch[0]].vl[1]+pt[ch[1]].vl[1]+pt[p].vl[0];
}
void split(int p,ll vl,int &pL,int &pR)
{
	if(!p) {pL=pR=0;return;}
	if(vl<pt[p].vl[0]) pR=p,split(pt[p].ch[0],vl,pL,pt[p].ch[0]);
	else pL=p,split(pt[p].ch[1],vl,pt[p].ch[1],pR);pu(p);
}
int merge(int pL,int pR)
{
	if(!pL || !pR) return pL|pR;
	if(pt[pL].w<pt[pR].w) {pt[pL].ch[1]=merge(pt[pL].ch[1],pR);pu(pL);return pL;}
	else {pt[pR].ch[0]=merge(pL,pt[pR].ch[0]);pu(pR);return pR;}
}
void ins(int &p,ll vl) {int p1,p2;split(p,vl,p1,p2);p=merge(merge(p1,New(vl)),p2);}
void dlt(int &p,ll vl)
{
	int p1,p2,p3,t1,t2;split(p,vl,p1,p2);split(p1,vl-1,p1,p3);
	if(p3) bin[++bin[0]]=p3;t1=pt[p3].ch[0];t2=pt[p3].ch[1];
	p=merge(merge(merge(p1,t1),t2),p2);
}
ll qSm(int p,int rk,bool fl=0)
{
	if(!rk) return 0;ll res=0;
	while(p)
	{
		int t=pt[pt[p].ch[0]].sz+1;if(rk>=t) res+=pt[pt[p].ch[0]].vl[1]+pt[p].vl[0];
		if(rk==t) return res;p=pt[p].ch[rk>t];if(rk>t) rk-=t;
	}return INF;
}
void dfs(int u,int f)
{fa[u]=f;for(auto i:e[u]) {int v=i.v,w=i.w;if(v!=f) fe[v]=w,ins(rt[u],w),dfs(v,u);}}
void dfs1(int u,int f,int x)
{
	if(f) dlt(rt[f],dp[u][1]-dp[u][0]+fe[u]);dp[u][0]=dp[u][1]=0;
	for(auto i:e1[u])
	{int v=i.v;if(v!=f) dfs1(v,u,x),dp[u][0]+=dp[v][0],dp[u][1]+=dp[v][0];}
	dp[u][0]+=qSm(rt[u],e[u].size()-x);dp[u][1]+=qSm(rt[u],e[u].size()-x-1);
	dp[u][0]=min(dp[u][0],fa[u]?dp[u][1]+fe[u]:INF);
	if(f) ins(rt[f],dp[u][1]-dp[u][0]+fe[u]);
}
int main()
{
	srand(time(0));scanf("%d",&n);
	for(int i=1,u,v,w;i<n;++i)
		scanf("%d %d %d",&u,&v,&w),e[u].pb((Edge) {v,w}),e[v].pb((Edge) {u,w});
	dfs(1,0);for(int i=1;i<=n;++i) vc[e[i].size()].pb(i);
	for(int i=n-1;i>=0;--i)
	{
		for(auto j:vc[i+1])
		{
			st[++st[0]]=j;vs[j]=1;
			for(auto k:e[j]) if(vs[k.v]) e1[j].pb(k),e1[k.v].pb((Edge) {j,k.w});
		}
		for(int j=1,u=st[j];j<=st[0];++j,u=st[j]) if(!vs[fa[u]])
			dfs1(u,fa[u],i),ans[i]+=dp[u][0];
	}for(int i=0;i<n;++i) printf("%lld ",ans[i]);return 0;
}