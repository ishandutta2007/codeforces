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
int n,m,fa[100005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,x,y;i<=m;i++) read(x),read(y),mrg(x,y);
	int cnt=0;for(int i=1;i<=n;i++) cnt+=getf(i)==i;
	return printf("%d\n",m-n+cnt),0;
}