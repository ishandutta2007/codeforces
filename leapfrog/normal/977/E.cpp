#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T,typename... A>inline void read(T &t,A &...a) {read(t),read(a...);}
int n,m,tot=0,fr[200005],to[200005],fa[200005],g[200005],deg[200005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {int u=getf(x),v=getf(y);if(u^v) fa[u]=v;}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) read(fr[i],to[i]),mrg(fr[i],to[i]),deg[fr[i]]++,deg[to[i]]++;
	for(int i=1;i<=n;i++) g[getf(i)]|=(deg[i]!=2);
	for(int i=1;i<=n;i++) if(getf(i)==i&&!g[i]) tot++;
	return printf("%d\n",tot),0;
}