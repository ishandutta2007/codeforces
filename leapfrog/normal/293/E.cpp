//{{{
#include<bits/stdc++.h>
#define ri register int
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
struct edge{int to,w,nxt;}e[200005];int et,head[100005];
int n,L,W,sz[100005],T[100005],mnd,rt,at,bt;char v[100005];ll res=0;
struct node{int ds,sm;char operator<(node b) const {return sm<b.sm;}}a[100005],b[100005];
inline void Tadd(int x,int w) {if(x>=0) for(++x;x<=L+1;x+=x&(-x)) T[x]+=w;}
inline int Tqry(int x) {int r=0;if(x>=0) for(++x;x;x-=x&(-x)) r+=T[x];return r;}
inline void Tclr(int x) {for(++x;x<=100001;x+=x&(-x)) if(T[x]) T[x]=0;else return;}
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void init(int x,int fa)
{
	sz[x]=1;for(int i=head[x];i;i=e[i].nxt)
		if(!v[e[i].to]&&e[i].to!=fa) init(e[i].to,x),sz[x]+=sz[e[i].to];
}
inline void getrt(int x,int fa,int tot)
{
	int mx=tot-sz[x];for(int i=head[x];i;i=e[i].nxt)
		if(!v[e[i].to]&&e[i].to!=fa) mx=max(mx,sz[e[i].to]),getrt(e[i].to,x,tot);
	if(mx<=mnd) mnd=mx,rt=x;
}
inline void ins(int x,int fa,int ds,int sm)
{
	if(sm<=W&&ds<=L) b[++bt]=a[++at]=(node){ds,sm};else return;
	for(int i=head[x];i;i=e[i].nxt) if(!v[e[i].to]&&e[i].to!=fa) ins(e[i].to,x,ds+1,sm+e[i].w);
}
inline void calc(int n,node *a,int fg)
{
	sort(a+1,a+n+1);ll rs=0;int lt=1;
	for(int rt=n;rt;rt--)
	{
		while(a[lt].sm+a[rt].sm<=W&&lt<=n) Tadd(a[lt++].ds,1);
		rs+=Tqry(L-a[rt].ds)-((a[rt].ds<<1)<=L&&(a[rt].sm<<1)<=W);
	}
	//for(int i=1;i<=n;i++) printf("<%d,%d>%c",a[i].ds,a[i].sm,i==n?'\n':' ');
	//printf("qwq %lld\n",rs);
	res+=fg?-rs:rs;for(int i=1;i<lt;i++) Tclr(a[i].ds);
}
inline void solve(int x)
{
	if(v[x]) return;else init(x,0),v[x]=1,at=0,b[bt=1]=(node){0,0};
	for(int i=head[x];i;i=e[i].nxt) if(!v[e[i].to]) at=0,ins(e[i].to,x,1,e[i].w),calc(at,a,1);calc(bt,b,0);
	for(int i=head[x];i;i=e[i].nxt) if(!v[e[i].to]) mnd=1e9,getrt(e[i].to,x,sz[x]),solve(rt);
}
int main()
{
	read(n),read(L),read(W);
	for(int i=2,w,f;i<=n;i++) read(f),read(w),adde(i,f,w),adde(f,i,w);
	return mnd=1e9,init(1,0),getrt(1,0,n),solve(rt),printf("%lld\n",res>>1),0;
}