//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
const int N=100005,B=635;int Sz,Bc,n,m,fa[N],tp[N],bl[N],L[B],R[B],tag[N],cg[N];
inline void upd(int x) {if(cg[bl[x]]<=Sz) tp[x]=bl[fa[x]]^bl[x]?fa[x]:tp[fa[x]];}
inline int gett(int x) {return cg[bl[x]]>Sz?max(1,fa[x]-tag[bl[x]]):tp[x];}
inline int getf(int x) {return cg[bl[x]]>Sz?max(1,fa[x]-tag[bl[x]]):fa[x];}
inline void chgbl(int id,int w)
{
	if(cg[id]>Sz) return tag[id]=min(tag[id]+w,n),void();
	for(int i=L[id];i<=R[id];i++) fa[i]=max(fa[i]-w,1),upd(i);
}
inline void modif(int l,int r,int c)
{
	int le=bl[l],ri=bl[r];
	if(le==ri)
	{
		for(int i=l;i<=r;i++) fa[i]=max(fa[i]-c,1);
		for(int i=l;i<=R[le];i++) upd(i);
		return;
	}
	for(int i=l;i<=R[le];i++) fa[i]=max(fa[i]-c,1);
	for(int i=l;i<=R[le];i++) upd(i);
	for(int i=L[ri];i<=r;i++) fa[i]=max(fa[i]-c,1);
	for(int i=L[ri];i<=R[ri];i++) upd(i);
	for(int i=le+1;i<ri;i++) chgbl(i,c),cg[i]++;
}
inline int LCA(const int &x,const int &y)
{
	int ux,uy;if(x==y) return x;else ux=gett(x),uy=gett(y);
	//printf("%d %d -> %d %d\n",x,y,ux,uy);
	if(bl[ux]^bl[uy]) return bl[ux]<bl[uy]?LCA(x,uy):LCA(ux,y);
	if(ux^uy) return ux>uy?LCA(ux,y):LCA(x,uy);
	return x<y?LCA(x,getf(y)):LCA(getf(x),y);
}
signed main()
{
	read(n),read(m),Sz=sqrt(n),Bc=0,fa[1]=tp[1]=1;
	for(int i=1;i<=n;i++) bl[i]=(i-1)/Sz+1;
	for(int i=1;i<=n+1;i++) if(bl[i]^bl[i-1]) {R[Bc]=i-1;if(i^(n+1)) L[++Bc]=i;}
	for(int i=2;i<=n;i++) read(fa[i]),upd(i);
	for(int ls=0,op,l,r,x;m--;)
	{
		read(op),read(l),read(r);//,l^=ls,r^=ls;
		if(op&1) read(x),modif(l,r,x);else printf("%d\n",ls=LCA(l,r));
		//for(int i=1;i<=n;i++) printf("%d%c",gett(i),i==n?'\n':' ');
		//for(int i=1;i<=n;i++) printf("%d%c",getf(i),i==n?'\n':' ');
	}
	return 0;
}