//Coded by Kamiyama_Shiki on 2021.11.19 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005;int n,m;
namespace DSU
{
	int fa[N],sz[N],s1[N],s2[N],tp;
	inline int getf(int x) {return fa[x]==x?x:getf(fa[x]);}
	inline void mrg(int x,int y)
	{
		x=getf(x),y=getf(y);if(x==y) return;else if(sz[x]>sz[y]) swap(x,y);
		tp++,s1[tp]=x,s2[tp]=y,fa[x]=y,sz[y]+=sz[x];
	}
	inline int sam(int x,int y) {return getf(x)==getf(y);}
	inline void pop(int tw) {while(tp>tw) fa[s1[tp]]=s1[tp],sz[s2[tp]]-=sz[s1[tp]],tp--;}
}
struct mdf{int x,y,f,id;char operator<(mdf b) {return x^b.x?x<b.x:y^b.y?y<b.y:id<b.id;}}d[N<<1];int dt=0;
vector<int>T[N<<2];int rs[N];struct qry{int x,y;}q[N],e[N<<1];char vs[N<<1];int id[N][2];int et=0;
inline void modif(int x,int l,int r,int dl,int dr,int dw)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) T[x].push_back(dw);
	else modif(x<<1,l,(l+r)>>1,dl,dr,dw),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dw);
}
inline void solve(int x,int l,int r)
{
	int st=DSU::tp;for(auto i:T[x]) if(vs[i]) DSU::mrg(e[i].x,e[i].y);
	if(l^r) return solve(x<<1,l,(l+r)>>1),solve(x<<1|1,((l+r)>>1)+1,r),DSU::pop(st);
	if(!q[l].x) rs[l]=rs[l-1],vs[id[l][rs[l]]]^=1,DSU::pop(st);
	else rs[l]=DSU::sam((q[l].x+rs[l-1]-1)%n+1,(q[l].y+rs[l-1]-1)%n+1),DSU::pop(st);
}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) DSU::fa[i]=i,DSU::sz[i]=1;
	for(int i=1,id,x,y;i<=m;i++)
	{
		read(id,x,y);if(!(id&1)) q[i]=(qry){x,y};
		else d[++dt]=(mdf){min(x,y),max(x,y),0,i},x=x%n+1,y=y%n+1,d[++dt]=(mdf){min(x,y),max(x,y),1,i};
	}sort(d+1,d+dt+1),e[et=1]=(qry){d[1].x,d[1].y},id[d[1].id][d[1].f]=1;
	for(int i=2,nw;i<=dt;i++)
	{
		nw=(d[i].x!=d[i-1].x||d[i].y!=d[i-1].y)?m:d[i].id;
		if(d[i-1].id<nw) modif(1,1,m,d[i-1].id+1,nw,et);
		if(d[i].x!=d[i-1].x||d[i].y!=d[i-1].y) e[++et]=(qry){d[i].x,d[i].y};
		id[d[i].id][d[i].f]=et;
	}if(d[dt].id<m) modif(1,1,m,d[dt].id+1,m,et);
	solve(1,1,m);for(int i=1;i<=m;i++) if(q[i].x) putchar(48^rs[i]);
	return putchar('\n'),0;
}