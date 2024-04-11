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
struct Edge{int fr,tw,we;bool operator<(Edge b) const {return we>b.we;}}e[200005];
int n,m,a[100005],b[100005],fa[200005],et=0;
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
int main()
{
	read(n),read(m);long long res=0;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=m;i++) read(b[i]);
	for(int i=1;i<=n+m;i++) fa[i]=i;
	for(int i=1,w,x;i<=n;i++) {read(w);while(w--) read(x),e[++et]=(Edge){i,x+n,a[i]+b[x]},res+=a[i]+b[x];}
	sort(e+1,e+et+1);for(int i=1;i<=et;i++) if(getf(e[i].fr)^getf(e[i].tw)) fa[getf(e[i].fr)]=getf(e[i].tw),res-=e[i].we;
	return printf("%lld\n",res),0;
}