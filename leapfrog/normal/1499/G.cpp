//Coded by Kamiyama_Shiki on 2021.11.01 {{{
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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=400005,P=998244353;int n1,n2,m,n,etc;
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void pls(int &x,int y) {(x+=y)>=P?x-=P:x;}
int fa[N],vl[N][2],xr[N],fg[N],rs=0;
inline int getf(int x)
{
	if(fa[x]==x) return x;else if(fa[fa[x]]==fa[x]) return fa[x];
	int tp=fa[x];return fa[x]=getf(fa[x]),xr[x]^=xr[tp],fa[x];
}
inline void merge(int u,int v)
{
	int x=getf(u),y=getf(v);if(x==y) return;
	rs=(1ll*rs+P-vl[x][xr[x]]+P-vl[y][xr[y]])%P,xr[x]^=xr[y],fa[x]=y;
	pls(vl[y][0],vl[x][xr[x]]),pls(vl[y][1],vl[x][!xr[x]]),pls(rs,vl[y][xr[y]]);
}
inline void rev(int x) {x=getf(x),rs=(1ll*rs-vl[x][xr[x]]+vl[x][!xr[x]]+P)%P,xr[x]^=1;}
inline int col(int x) {return getf(x),xr[x]^(x==getf(x)?0:xr[getf(x)]);}
inline void ins(int x,int y,int id)
{
	//printf("add %d %d %d\n",x,y,id);
	fa[id]=id,vl[id][1]=ksm(2,id),vl[id][0]=xr[id]=0;
	if(!fg[x]&&!fg[y]) {fg[x]=fg[y]=id;return;}
	else if(fg[x]<fg[y]) swap(x,y);
	if(fg[x]&&!fg[y])
	{
		if(!col(fg[x])) rev(id);
		merge(id,fg[x]),fg[y]=id,fg[x]=0;return;
	}
	if(col(fg[x])^col(fg[y])) rev(fg[x]);
	if(!col(fg[x])) rev(id);
	merge(fg[x],id),merge(fg[y],id),fg[x]=fg[y]=0;
}
inline void debug()
{
	vector<int>rs;for(int i=1;i<=etc;i++) if(col(i)) rs.push_back(i);
	printf("%d ",(int)rs.size());for(auto x:rs) printf("%d ",x);putchar('\n');
}
int main()
{
	read(n1,n2,m),n=n1+n2;
	for(int i=1,x,y;i<=m;i++) read(x,y),ins(x,y+n1,++etc);
	int Ca;for(read(Ca);Ca--;)
	{
		int fg,x,y;read(fg);if(fg&1) read(x,y);
		if(fg==2) debug();else ins(x,y+n1,++etc),printf("%d\n",rs);
		fflush(stdout);
	}return 0;
}
//
//
//
//
//
//
//