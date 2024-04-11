//{{{
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
struct segm{int ls,rs,lz;}T[5000005];int tt,m;ll n;
struct qwq{char ch[6];ll l,r;}q[50005];int fa[5000005];
vector<pair<int,int> >e[5000005];char rs[50005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
inline char chk(int x,int y) {return getf(x)==getf(y);}
inline void pushdw(int x)
{
	int v=T[x].lz;if(!T[x].lz) return;else T[x].lz=0;
	T[T[x].ls?T[x].ls:T[x].ls=++tt].lz=v;
	T[T[x].rs?T[x].rs:T[x].rs=++tt].lz=v;
}
inline void modif(int x,ll l,ll r,ll dl,ll dr,int dv)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return T[x].lz=dv,void();
	pushdw(x),modif(T[x].ls,l,(l+r)>>1,dl,dr,dv),modif(T[x].rs,((l+r)>>1)+1,r,dl,dr,dv);
}
inline void solve(int x,int y)
{
	//printf("! %d %d\n",x,y);for(int i=100000000;i--;);
	if(T[x].lz&&T[y].lz) return e[min(T[x].lz,T[y].lz)].push_back(make_pair(x,y)),void();
	if(T[x].lz) return solve(x,T[y].ls),solve(x,T[y].rs);
	if(T[y].lz) return solve(T[x].ls,y),solve(T[x].rs,y);
	return solve(T[x].ls,T[y].ls),solve(T[x].rs,T[y].rs);
}
inline int fnd(int x,ll l,ll r,ll dw)
{
	if(T[x].lz) return x;
	if(dw<=((l+r)>>1)) return fnd(T[x].ls,l,(l+r)>>1,dw);
	else return fnd(T[x].rs,((l+r)>>1)+1,r,dw);
}
int main()
{
	read(n,m),n=1ll<<n,n--,++tt,T[1].lz=m+1;
	for(int i=1;i<=m;i++) scanf("%s",q[i].ch),read(q[i].l),read(q[i].r);
	for(int i=1;i<=m;i++) if(*q[i].ch=='b') modif(1,0,n,q[i].l,q[i].r,i);
	//for(int i=1;i<=tt;i++) if(T[i].ls) printf("%d %d\n",i,T[i].ls);
	//for(int i=1;i<=tt;i++) if(T[i].rs) printf("%d %d\n",i,T[i].rs);
	//for(int i=1;i<=tt;i++) printf("%d%c",T[i].lz,i==tt?'\n':' ');
	for(int i=1;i<=tt;i++) if(T[i].ls&&T[i].rs) solve(T[i].ls,T[i].rs);
	for(int i=1;i<=tt;i++) fa[i]=i;
	for(int i=m;i>=1;i--)
	{
		for(auto x:e[i+1]) mrg(x.first,x.second);
		if(*q[i].ch=='a') rs[i]=chk(fnd(1,0,n,q[i].l),fnd(1,0,n,q[i].r));
	}
	for(int i=1;i<=m;i++) if(*q[i].ch=='a') printf("%d\n",rs[i]);
	return 0;
}