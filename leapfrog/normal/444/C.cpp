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
const int N=200005;int n,Q;
struct seg{ll sm,tg;int ln;}T[N<<2];
inline void pushup(int x) {T[x].sm=T[x<<1].sm+T[x<<1|1].sm;}
inline void allc(int x,ll c) {T[x].sm+=c*T[x].ln,T[x].tg+=c;}
inline void pushdw(int x) {if(T[x].tg) allc(x<<1,T[x].tg),allc(x<<1|1,T[x].tg),T[x].tg=0;}
inline void build(int x,int l,int r)
{
	T[x].ln=r-l+1;if(l==r) return T[x].sm=T[x].tg=0,void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r);
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline ll query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return T[x].sm;else pushdw(x);
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
struct ${int l,r;mutable int v;char operator<($ b) const {return l<b.l;}};
typedef set<$>::iterator IT;set<$>S;
inline IT split(int wh)
{
	IT it=S.lower_bound(($){wh,-1,0});
	if(it!=S.end()&&it->l==wh) return it;else it--;
	int l=it->l,r=it->r,v=it->v;S.erase(it);
	return S.insert(($){l,wh-1,v}),S.insert(($){wh,r,v}).first;
}
inline void col(int l,int r,int v)
{
	IT ri=split(r+1),le=split(l);
	for(IT it=le;it!=ri;it++) modif(1,1,n,it->l,it->r,abs(v-it->v));
	S.erase(le,ri),S.insert(($){l,r,v});
}
int main()
{
	read(n,Q),build(1,1,n),S.insert(($){n+1,n+1,0});
	for(int i=1;i<=n;i++) S.insert(($){i,i,i});
	for(int fg,l,r,x;Q--;)
	{
		read(fg,l,r);if(fg&1) read(x),col(l,r,x);
		else printf("%lld\n",query(1,1,n,l,r));
		//for(auto x:S) printf("<%d,%d,%d>%c",x.l,x.r,x.v,x.r==n+1?'\n':' ');
	}return 0;
}