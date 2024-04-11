//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
struct node{int ls,rs,sz,vl,an,rn,lz,fg;}T[200005];int n,m,a[200005],tt,rt;
struct ${int c,q;char operator<($ b) const {return q>b.q||(q==b.q&&c<b.c);}}b[200005];
inline void pushup(int x) {T[x].sz=T[T[x].ls].sz+T[T[x].rs].sz+1;}
inline void allc(int x,int w,int t) {if(x) T[x].lz+=w,T[x].fg+=t,T[x].an+=t,T[x].vl-=w;}
inline void pushdw(int x) {if(x&&T[x].lz) allc(T[x].ls,T[x].lz,T[x].fg),allc(T[x].rs,T[x].lz,T[x].fg),T[x].lz=T[x].fg=0;}
inline void split(int x,int k,int &a,int &b)
{
	if(!x) return a=b=0,void();else pushdw(x);
	if(T[x].vl<=k) a=x,split(T[x].rs,k,T[a].rs,b),pushup(a);
	else b=x,split(T[x].ls,k,a,T[b].ls),pushup(b);
}
inline int merge(int x,int y)
{
	if(!x||!y||!(x^y)) return x|y;else pushdw(x),pushdw(y);
	if(T[x].rn<=T[y].rn) return T[x].rs=merge(T[x].rs,y),pushup(x),x;
	else return T[y].ls=merge(x,T[y].ls),pushup(y),y;
}
inline void clear(int x,int &tw)
{
	if(!x) return;else pushdw(x),clear(T[x].ls,tw),clear(T[x].rs,tw);
	T[x].ls=T[x].rs=0,T[x].rn=rand(),T[x].sz=1;int a,b;
	split(tw,T[x].vl-1,a,b),tw=merge(a,merge(x,b));
}
inline void pullout(int x) {if(x) pushdw(x),pullout(T[x].ls),pullout(T[x].rs);}
int main()
{
	srand(time(0)),read(m);for(int i=1;i<=m;i++) read(b[i].c),read(b[i].q);
	sort(b+1,b+m+1),read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,x,y;i<=n;i++) T[i]=(node){0,0,1,a[i],0,rand(),0,0},split(rt,a[i]-1,x,y),rt=merge(x,merge(i,y));
	for(int i=1,x,y,z;i<=m;i++)
	{
		split(rt,b[i].c-1,x,y),allc(y,b[i].c,1);
		split(y,b[i].c,y,z),rt=merge(x,z),clear(y,rt);
	}
	pullout(rt);for(int i=1;i<=n;i++) printf("%d%c",T[i].an,i==n?'\n':' ');
	return 0;
}