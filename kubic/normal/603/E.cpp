#include <bits/stdc++.h>
using namespace std;
#define N 300005
int n,m,cntO,fa[N],sz[N],st[N],ans[N];
struct Edge {int u,v,w,id;}e[N],e1[N];
bool cmp(Edge x,Edge y) {return x.w==y.w?x.id<y.id:x.w<y.w;}
void clear() {cntO=n;for(int i=1;i<=n;++i) fa[i]=i,sz[i]=1;}
int findRt(int x) {return x==fa[x]?x:findRt(fa[x]);}
void merge(Edge z)
{
	int x=findRt(z.u),y=findRt(z.v);if(x==y) return;
	if(sz[x]&1 && sz[y]&1) cntO-=2;
	if(sz[x]<sz[y]) fa[x]=y,sz[y]+=sz[x],st[++st[0]]=x;
	else fa[y]=x,sz[x]+=sz[y],st[++st[0]]=y;
}
void rev(int lim)
{
	while(st[0]>lim)
	{
		int x=st[st[0]--],y=fa[x];fa[x]=x;sz[y]-=sz[x];
		if(sz[x]&1 && sz[y]&1) cntO+=2;
	}
}
void slv(int l,int r,int wL,int wR)
{
	if(l>r) return;int mid=(l+r)/2,tmp1=st[0],tmp2=0;
	for(int i=l;i<=mid;++i) if(e1[i].w<wL) merge(e1[i]);tmp2=st[0];
	for(int i=wL;i<=wR;++i) if(e[i].id<=mid)
	{merge(e[i]);if(!cntO) {ans[mid]=i;break;}}rev(tmp2);
	if(!ans[mid]) {slv(mid+1,r,wL,wR);rev(tmp1);return;}
	slv(mid+1,r,wL,ans[mid]);rev(tmp1);
	for(int i=wL;i<ans[mid];++i) if(e[i].id<l) merge(e[i]);
	slv(l,mid-1,ans[mid],wR);rev(tmp1);
}
int main()
{
	scanf("%d %d",&n,&m);clear();
	for(int i=1,u,v,w;i<=m;++i)
		scanf("%d %d %d",&u,&v,&w),e[i]=(Edge) {u,v,w,i},e1[i]=e[i];
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;++i) e1[e[i].id].w=i;slv(1,m,1,m);
	for(int i=1;i<=m;++i) printf("%d\n",ans[i]?e[ans[i]].w:-1);
	return 0;
}