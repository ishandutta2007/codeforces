//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct edge{int x,y,w;bool operator<(edge b) {return w>b.w;}}e[200005];
int n,m,fa[200005],tag[200005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) tag[x]|=tag[y],fa[y]=x;}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) fa[i]=i,tag[i]=0;
	for(int i=1;i<=m;i++) read(e[i].x),read(e[i].y),read(e[i].w);
	sort(e+1,e+m+1);long long rs=0;
	for(int i=1;i<=m;i++)
	{
		int Fx=getf(e[i].x),Fy=getf(e[i].y);
		if((Fx==Fy&&tag[Fx])||(Fx!=Fy&&tag[Fx]&&tag[Fy])) continue;else rs+=e[i].w;
		if(Fx==Fy) tag[getf(e[i].x)]=1;else mrg(e[i].x,e[i].y);
	}
	return printf("%lld\n",rs),0;
}