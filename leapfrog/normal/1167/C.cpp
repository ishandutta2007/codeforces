//Coded by leapfrog on 2021.10.27 {{{
//
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
const int N=500005;int n,m,sz[N],fa[N];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y,sz[y]+=sz[x];}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(int i=1,k,fs,x;i<=m;i++) {read(k),fs=0;while(k--) read(x),fs?mrg(fs,x),fs=x:fs=x;}
	for(int i=1;i<=n;i++) printf("%d%c",sz[getf(i)],i==n?'\n':' ');
	return 0;
}