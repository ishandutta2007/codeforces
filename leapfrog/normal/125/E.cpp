//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct node{int x,y;double w;int id;bool operator<(node b) {return w<b.w;}}e[100005],e1[100005],e2[100005];
int n,m,K,fa[10005],t1,t2;
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline char mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) return fa[x]=y,1;else return 0;}
inline char check(ll w)
{
	for(int i=1;i<=t1;i++) e[i]=e1[i],e[i].w+=w/100000.0;
	int cnt=0;for(int i=1;i<=t2;i++) e[i+t1]=e2[i];
	sort(e+1,e+m+1);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) if(mrg(e[i].x,e[i].y)) cnt+=(e[i].x==1||e[i].y==1);
	return cnt<=K;
}
int main()
{
	read(n),read(m),read(K);ll le=-1e16-7,ri=1e16+7,rs=1e16+7;
	for(int i=1,x,y,w;i<=m;i++) {read(x),read(y),read(w);if(x==1||y==1) e1[++t1]=(node){x,y,w,i};else e2[++t2]=(node){x,y,w,i};}
	while(le<=ri) {ll md=(le+ri)/2;if(check(md)) rs=md,ri=md-1;else le=md+1;}
	if(!check(rs)) return puts("-1"),0;else printf("%d\n",n-1);
	for(int i=1;i<=t1;i++) e[i]=e1[i],e[i].w+=rs/100000.0;
	for(int i=1;i<=t2;i++) e[i+t1]=e2[i];
	sort(e+1,e+m+1);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) if(mrg(e[i].x,e[i].y)) printf("%d%c",e[i].id,i==n-1?'\n':' ');
	return 0;
}