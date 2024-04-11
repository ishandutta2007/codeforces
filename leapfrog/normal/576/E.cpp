//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int tp,ni[1000005],nx[1000005],nz[1000005];
pair<int,int>e[500005];int fa[55][1000005],len[55][1000005];
int n,m,q,K,a[500005],c[500005],p[500005],fr[500005],tw[500005];vector<int>E[2000005];
inline void init() {for(int k=1;k<=K;k++) for(int i=1;i<=n+n;i++) fa[k][i]=i,len[k][i]=1;}
inline int getf(int id,int x) {return fa[id][x]==x?x:getf(id,fa[id][x]);}
inline void mrg(int id,int a,int b)
{
	if(a==b) return;else if(len[id][a]>len[id][b]) swap(a,b);
	int z=len[id][a]==len[id][b];tp++,ni[tp]=id,nx[tp]=a,nz[tp]=z,fa[id][a]=b,len[id][b]+=z;
}
inline void back() {int id=ni[tp],x=nx[tp],z=nz[tp];tp--,len[id][fa[id][x]]-=z,fa[id][x]=x;}
inline void motif(int x,int l,int r,int dl,int dr,int dw)
{
	if(l>dr||dl>r||dl>dr) return;else if(dl<=l&&r<=dr) return(void)(E[x].push_back(dw));
	motif(x<<1,l,(l+r)>>1,dl,dr,dw),motif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dw);
}
inline void solve(int x,int l,int r)
{
	int nwtp=tp;
	for(int i=0;i<(int)E[x].size();i++)
	{
		int g=E[x][i],u=fr[a[g]],v=tw[a[g]];
		if(c[g]) mrg(c[g],getf(c[g],u),getf(c[g],v+n)),mrg(c[g],getf(c[g],u+n),getf(c[g],v));
	}
	if(l==r)
	{
		int u=fr[a[l]],v=tw[a[l]];
		if(getf(c[l],u)==getf(c[l],v)) puts("NO"),c[l]=p[a[l]];
		else puts("YES"),p[a[l]]=c[l];
	}else solve(x<<1,l,(l+r)>>1),solve(x<<1|1,((l+r)>>1)+1,r);
	while(tp>nwtp) back();
}
int main()
{
	read(n),read(m),read(K),read(q),init();
	for(int i=1;i<=m;i++) read(fr[i]),read(tw[i]),p[i]=q+1;
	for(int i=1;i<=q;i++) read(a[i]),read(c[i]);
	for(int i=q;i;i--) motif(1,1,q,i+1,p[a[i]]-1,i),p[a[i]]=i;
	return memset(p,0,sizeof(p)),solve(1,1,q),0;
}