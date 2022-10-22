#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
#define set(a,vl) memset(a,vl,sizeof(a))
int n,n1,ds[N],L[N],R[N],w[N],cur[N];bool tg[N],ans[N];
int cntE,hd[N];struct Edge {int v,w,nxt;}e[N];
void addE(int u,int v,int w)
{
	e[cntE]=(Edge) {v,w,hd[u]};hd[u]=cntE++;
	e[cntE]=(Edge) {u,w,hd[v]};hd[v]=cntE++;
}
void dfs(int u)
{
	for(int i=cur[u];~i;i=cur[u])
	{
		cur[u]=e[i].nxt;if(tg[i]) continue;
		tg[i]=tg[i^1]=1;dfs(e[i].v);ans[e[i].w]=u<e[i].v;
	}
}
int main()
{
	scanf("%d",&n);n1=n;set(hd,-1);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&L[i],&R[i]);++R[i];
		ds[++ds[0]]=L[i];ds[++ds[0]]=R[i];
	}sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=n;++i)
	{
		L[i]=lower_bound(ds+1,ds+ds[0]+1,L[i])-ds;++w[L[i]];
		R[i]=lower_bound(ds+1,ds+ds[0]+1,R[i])-ds;--w[R[i]];
	}
	for(int i=1;i<=ds[0];++i)
	{w[i]+=w[i-1];if(w[i]&1) ++n,L[n]=i,R[n]=i+1;}
	for(int i=1;i<=n;++i) addE(L[i],R[i],i);
	for(int i=1;i<=ds[0];++i) cur[i]=hd[i];
	for(int i=1;i<=ds[0];++i) if(~cur[i]) dfs(i);
	for(int i=1;i<=n1;++i) printf("%d ",ans[i]);return 0;
}