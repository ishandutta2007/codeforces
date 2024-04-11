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
int n,m,P,fa[100005],sz[100005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) sz[x]+=sz[y],fa[y]=x;}
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n),read(m),read(P);for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	int qwq=1,k=0;for(int i=1,x,y;i<=m;i++) read(x),read(y),mrg(x,y);
	for(int i=1;i<=n;i++) if(getf(i)==i) qwq=1ll*qwq*sz[i]%P,++k;
	return printf("%lld\n",k<2?1ll%P:1ll*qwq*ksm(n,k-2)%P),0;
}