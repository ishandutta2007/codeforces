#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define LIM 1000000
#define ll long long
#define mid ((l+r)/2)
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const ll INF=1e18;char *P1,*P2,buf[LIM];
int n,m,w[N],id[N],L[N],R[N];ll dp[N];vector<int> e[N],vc1[N],vc2[N];
struct Seg {ll vl,tg;}sg[N*4];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
void mdf(int p,ll vl) {sg[p].vl+=vl;sg[p].tg+=vl;}
void pu(int p) {sg[p].vl=min(sg[p*2].vl,sg[p*2+1].vl);}
void pd(int p) {if(sg[p].tg) mdf(p*2,sg[p].tg),mdf(p*2+1,sg[p].tg),sg[p].tg=0;}
void build(int p,int l,int r)
{sg[p].vl=INF;if(l==r) return;build(p*2,l,mid);build(p*2+1,mid+1,r);}
void upd1(int p,int l,int r,int x,ll vl)
{
	if(l==r) {sg[p].vl=vl;return;}pd(p);
	if(x<=mid) upd1(p*2,l,mid,x,vl);else upd1(p*2+1,mid+1,r,x,vl);pu(p);
}
void upd2(int p,int l,int r,int qL,int qR,ll vl)
{
	if(qL>qR) return;if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p);
	if(qL<=mid) upd2(p*2,l,mid,qL,qR,vl);
	if(qR>mid) upd2(p*2+1,mid+1,r,qL,qR,vl);pu(p);
}
ll qMn(int p,int l,int r,int qL,int qR)
{
	if(qL>qR) return INF;if(l>=qL && r<=qR) return sg[p].vl;pd(p);ll res=INF;
	if(qL<=mid) res=qMn(p*2,l,mid,qL,qR);
	if(qR>mid) res=min(res,qMn(p*2+1,mid+1,r,qL,qR));return res;
}
void dfs1(int u,int f)
{
	L[u]=id[0]+1;for(int i=0;i<vc1[u].size();++i) id[vc1[u][i]]=++id[0];
	for(int i=0,v;i<e[u].size();++i) {v=e[u][i];if(v!=f) dfs1(v,u);}R[u]=id[0]; 
}
void dfs2(int u,int f)
{
	ll s=0;
	for(int i=0,v;i<e[u].size();++i)
	{
		v=e[u][i];if(v==f) continue;dfs2(v,u);
		if(dp[v]>=INF) {dp[u]=INF;return;}s+=dp[v];
	}for(int i=0,t;i<vc1[u].size();++i) t=vc1[u][i],upd1(1,1,m,id[t],s+w[t]);
	for(int i=0,t;i<vc2[u].size();++i) t=vc2[u][i],upd1(1,1,m,id[t],INF);
	for(int i=0,v;i<e[u].size();++i)
	{v=e[u][i];if(v!=f) upd2(1,1,m,L[v],R[v],s-dp[v]);}
	dp[u]=f?qMn(1,1,m,L[u],R[u]):s;
}
int main()
{
	n=rd();m=rd();build(1,1,m);
	for(int i=1,u,v;i<n;++i) u=rd(),v=rd(),e[u].pb(v),e[v].pb(u);
	for(int i=1,u,v;i<=m;++i) u=rd(),v=rd(),w[i]=rd(),vc1[u].pb(i),vc2[v].pb(i);
	dfs1(1,0);dfs2(1,0);if(dp[1]<INF) printf("%lld\n",dp[1]);else puts("-1");
	return 0; 
}