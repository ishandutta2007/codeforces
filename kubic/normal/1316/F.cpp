#include <bits/stdc++.h>
using namespace std;
#define N 600005
#define MOD 1000000007
#define mid (l+r>>1)
int n,m,d,ans,a[N],pw[N],ds[N],bc[N];
struct Query {int x,v;}q[N];
struct Seg {int v[4];}sg[N<<2];
int id(int x) {return lower_bound(ds+1,ds+ds[0]+1,x)-ds;}
int inv(int x) {return x==1?1:1ll*inv(MOD%x)*(MOD-MOD/x)%MOD;}
void pu(int p)
{
	sg[p].v[0]=sg[p<<1].v[0]+sg[p<<1|1].v[0];
	sg[p].v[1]=(sg[p<<1].v[1]+1ll*sg[p<<1|1].v[1]*pw[sg[p<<1].v[0]]%MOD)%MOD;
	sg[p].v[2]=(sg[p<<1|1].v[2]+1ll*sg[p<<1].v[2]*pw[sg[p<<1|1].v[0]]%MOD)%MOD;
	sg[p].v[3]=(1ll*sg[p<<1].v[3]*pw[sg[p<<1|1].v[0]]%MOD+1ll*sg[p<<1|1].v[3]*pw[sg[p<<1].v[0]]%MOD)%MOD;
	sg[p].v[3]=(sg[p].v[3]+1ll*sg[p<<1].v[1]*sg[p<<1|1].v[2]%MOD)%MOD;
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		sg[p].v[0]=bc[l];sg[p].v[1]=sg[p].v[2]=1ll*ds[l]*(pw[bc[l]]-1)%MOD;
		sg[p].v[3]=bc[l]>1?1ll*ds[l]*ds[l]%MOD*(1ll*(bc[l]-2)*pw[bc[l]-1]%MOD+1)%MOD:0;return;
	}build(p<<1,l,mid);build(p<<1|1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int x,int v)
{
	if(l==r)
	{
		bc[l]=sg[p].v[0]=v;sg[p].v[1]=sg[p].v[2]=1ll*ds[l]*(pw[v]-1)%MOD;
		sg[p].v[3]=v>1?1ll*ds[l]*ds[l]%MOD*(1ll*(v-2)*pw[v-1]%MOD+1)%MOD:0;return;
	}if(x<=mid) upd(p<<1,l,mid,x,v);else upd(p<<1|1,mid+1,r,x,v);pu(p);
}
int main()
{
	pw[0]=1;scanf("%d",&n);for(int i=1;i<=n;++i) pw[i]=(pw[i-1]<<1)%MOD;d=inv(pw[n]);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),ds[++ds[0]]=a[i];scanf("%d",&m);
	for(int i=1;i<=m;++i) scanf("%d %d",&q[i].x,&q[i].v),ds[++ds[0]]=q[i].v;
	sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=n;++i) a[i]=id(a[i]),++bc[a[i]];
	build(1,1,ds[0]);printf("%d\n",1ll*(sg[1].v[3]+MOD)*d%MOD);
	for(int i=1,x,v;i<=m;++i)
	{
		x=q[i].x;v=id(q[i].v);upd(1,1,ds[0],a[x],--bc[a[x]]);a[x]=v;upd(1,1,ds[0],v,++bc[v]);
		printf("%d\n",1ll*(sg[1].v[3]+MOD)*d%MOD);
	}return 0;
}