#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define mid ((l+r)/2)
#define pb push_back
int n,m,nw,fa[N],L[N],R[N],ds[N*2],F[N][3];vector<int> sg[N*4];
int qId(int x) {return lower_bound(ds+1,ds+ds[0]+1,x)-ds;}
int findRt(int u) {return u==fa[u]?u:fa[u]=findRt(fa[u]);}
void merge(int u,int v)
{
	u=findRt(u);v=findRt(v);
	if(u!=v) fa[u]=v,L[v]=min(L[v],L[u]),R[v]=max(R[v],R[u]);
}
void upd(int p,int l,int r,int qL,int qR,int u)
{
	if(qL>qR) return;if(l>=qL && r<=qR) {sg[p].pb(u);return;}
	if(qL<=mid) upd(p*2,l,mid,qL,qR,u);
	if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,u);
}
void upd1(int p,int l,int r,int x,int u)
{
	for(auto v:sg[p]) merge(u,v);
	if(!sg[p].empty()) sg[p].clear(),sg[p].pb(u);if(l==r) return;
	if(x<=mid) upd1(p*2,l,mid,x,u);else upd1(p*2+1,mid+1,r,x,u);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d %d",&F[i][0],&F[i][1],&F[i][2]);
		if(F[i][0]==1) ds[++ds[0]]=F[i][1],ds[++ds[0]]=F[i][2];
	}sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1,t,l,r,u,v;i<=n;++i) if(F[i][0]==1)
	{
		++nw;fa[nw]=nw;l=L[nw]=F[i][1]=qId(F[i][1]);
		r=R[nw]=F[i][2]=qId(F[i][2]);upd1(1,1,ds[0],l,nw);
		upd1(1,1,ds[0],r,nw);upd(1,1,ds[0],l+1,r-1,nw);
	}
	else
	{
		t=F[i][1];u=findRt(F[i][1]);v=findRt(F[i][2]);
		if(u==v) {puts("YES");continue;}
		if(L[u]<L[v] || R[u]>R[v]) {puts("NO");continue;}
		puts(L[v]<F[t][1] || R[v]>F[t][2]?"YES":"NO");
	}return 0;
}