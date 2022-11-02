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
const int N=3005;int n,fa[N],sz[N],vl[N],sm=0;
struct ${int x,y,w;char operator<($ b) const {return w<b.w;}}e[N];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
int main()
{
	read(n);for(int i=1;i<n;i++) read(e[i].x,e[i].y,e[i].w);
	for(int i=1;i<=n;i++) read(vl[i]),sz[i]=1,fa[i]=i,sm+=vl[i];
	sort(e+1,e+n);for(int i=1;i<n;i++)
	{
		int x=getf(e[i].x),y=getf(e[i].y);
		fa[y]=x,sz[x]+=sz[y],vl[x]+=vl[y];
		if(sz[x]>sm-vl[x]) return printf("%d\n",e[i].w),0;
	}return puts("0"),0;
}