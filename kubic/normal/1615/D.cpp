#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define pb push_back
int T,n,m,U[N],V[N],W[N],rt[N];bool ans,vl[N];vector<int> vc[N];
int pct(int x) {int res=0;while(x) ++res,x&=x-1;return res;}
int findRt(int u) {return u==rt[u]?u:rt[u]=findRt(rt[u]);}
bool merge(int u,int v,bool w)
{
	int rtU=findRt(u),rtV=findRt(v);bool t=vl[u]^vl[v]^w;
	if(rtU==rtV) {if(t) return 0;return 1;}
	if(vc[rtU].size()<vc[rtV].size()) swap(rtU,rtV);rt[rtV]=rtU;
	for(auto i:vc[rtV]) vl[i]^=t,vc[rtU].pb(i);vc[rtV].clear();return 1;
}
void slv()
{
	scanf("%d %d",&n,&m);ans=1;
	for(int i=1;i<=n;++i) rt[i]=i,vl[i]=0,vc[i].clear(),vc[i].pb(i);
	for(int i=1,u,v,w;i<n;++i)
	{scanf("%d %d %d",&u,&v,&w);U[i]=u;V[i]=v;W[i]=w;if(~w) w=pct(w),merge(u,v,w&1);}
	for(int i=1,u,v,w;i<=m;++i)
	{scanf("%d %d %d",&u,&v,&w);if(!ans) continue;if(!merge(u,v,w)) ans=0;}
	if(!ans) {puts("NO");return;}puts("YES");
	for(int i=1;i<n;++i) printf("%d %d %d\n",U[i],V[i],(~W[i]?W[i]:vl[U[i]]^vl[V[i]]));
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}