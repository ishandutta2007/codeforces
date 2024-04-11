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
const int N=200005;struct edge{int to,nxt;}e[N<<1];int et,head[N];
int n,sz[N],mnd,rt,tn[1<<20|5];char v[N],a[N];ll rs[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
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
inline void dfs(int x,int fa,int fg,int ds)
{
	tn[ds^=1<<a[x]]+=fg;for(int i=head[x];i;i=e[i].nxt)
		if(e[i].to!=fa&&!v[e[i].to]) dfs(e[i].to,x,fg,ds);
}
inline ll gets(int x,int fa,int ds)
{
	ds^=1<<a[x];ll sm=tn[ds];for(int i=0;i<20;i++) sm+=tn[ds^(1<<i)];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&!v[e[i].to]) sm+=gets(e[i].to,x,ds);
	return rs[x]+=sm,sm;
}
inline void calc(int x)
{
	dfs(x,0,1,0);ll sm=tn[0];for(int i=0;i<20;i++) sm+=tn[1<<i];
	for(int i=head[x];i;i=e[i].nxt) if(!v[e[i].to])
		dfs(e[i].to,x,-1,1<<a[x]),sm+=gets(e[i].to,x,0),dfs(e[i].to,x,1,1<<a[x]);
	rs[x]+=sm>>1,dfs(x,0,-1,0);
}
inline void solve(int x)
{
	v[x]=1,calc(x),init(x,0);for(int i=head[x];i;i=e[i].nxt)
		if(!v[e[i].to]) mnd=1e9,getrt(e[i].to,x,sz[e[i].to]),solve(rt);
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	scanf("%s",a+1),mnd=1e9,init(1,0);for(int i=1;i<=n;i++) a[i]-='a';
	getrt(1,0,n),solve(rt);for(int i=1;i<=n;i++) printf("%lld%c",rs[i]+1,i==n?'\n':' ');
	return 0;
}