//
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
struct node{int x,y,w;bool operator<(const node &b) const {return w<b.w;}}a[1000005];
int n,m,fa[100005];
inline int getf(int x) {return x==fa[x]?x:fa[x]=getf(fa[x]);}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) read(a[i].x),read(a[i].y),read(a[i].w);
	sort(a+2,a+m+1);int cnt=0;
	for(int i=2;i<=m;i++) if(getf(a[i].x)!=getf(a[i].y))
	{
		++cnt,fa[getf(a[i].x)]=getf(a[i].y);
		if(getf(a[1].x)==getf(a[1].y)) return printf("%d\n",a[i].w),0;
	}
	if(cnt!=n-1) return puts("1000000000"),0;
}