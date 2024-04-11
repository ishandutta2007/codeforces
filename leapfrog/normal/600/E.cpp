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
struct edge{int to,nxt;}e[200005];
struct node{int mx;long long ct;int ls,rs;}t[5000005];
int n,c[100005],q[500005],qt,tt,et,head[100005],rt[100005];long long r[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void Del(int &x) {q[++qt]=x,t[x]=(node){0,0,0,0},x=0;}
inline node& New(int &x) {return t[qt?(x=q[qt--]):(x=++tt)];}
inline node operator+(node a,node b) {if(a.mx<b.mx) return b;else if(a.mx>b.mx) return a;else return(node){a.mx,a.ct+b.ct};}
inline void up(node &a,node l,node r) {int ls=a.ls,rs=a.rs;a=l+r,a.ls=ls,a.rs=rs;}
inline void motif(int &x,int l,int r,int dw)
{
	x?t[x]:New(x);if(l==r) return(void)(t[x].mx++,t[x].ct=l);
	if(dw<=((l+r)>>1)) motif(t[x].ls,l,(l+r)>>1,dw),up(t[x],t[t[x].ls],t[t[x].rs]);
	else motif(t[x].rs,((l+r)>>1)+1,r,dw),up(t[x],t[t[x].ls],t[t[x].rs]);
}
inline int Mrg(int x,int y,int l,int r)
{
	if(!x||!y) return x|y;else if(x==y) return t[x].mx+=t[y].mx,Del(y),x;
	if(l==r) return t[x].mx+=t[y].mx,t[x].ct=l,Del(y),x;
	t[x].ls=Mrg(t[x].ls,t[y].ls,l,(l+r)>>1),t[x].rs=Mrg(t[x].rs,t[y].rs,((l+r)>>1)+1,r);
	return up(t[x],t[t[x].ls],t[t[x].rs]),Del(y),x;
}
inline void debug(int x,int l,int r)
{
	if(!x) return;else if(l==r) return(void)(printf("<%d,%d> ",l,t[x].mx));
	debug(t[x].ls,l,(l+r)>>1),debug(t[x].rs,((l+r)>>1)+1,r);
}
inline void dfs(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x),rt[x]=Mrg(rt[x],rt[e[i].to],1,n);
	motif(rt[x],1,n,c[x]),r[x]=t[rt[x]].ct;
}
int main()
{
	read(n),t[0].mx=t[0].ct=0;for(int i=1;i<=n;i++) read(c[i]);
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs(1,0);for(int i=1;i<=n;i++) printf("%lld%c",r[i],i==n?'\n':' ');
	return 0;
}