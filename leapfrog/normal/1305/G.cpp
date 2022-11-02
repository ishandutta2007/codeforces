//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
const int N=262144;int n,fa[N],ct[N];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline int mrg(int x,int y)
{
	x=getf(x),y=getf(y);if(x==y) return 0;
	int rs=ct[x]+ct[y]-1;return fa[x]=y,ct[y]=1,rs;
}
int main()
{
	read(n),ct[0]=1;ll rs=0;for(int i=0;i<N;i++) fa[i]=i;
	for(int i=1,x;i<=n;i++) read(x),ct[x]++,rs-=x;
	for(int S=N-1;~S;S--) for(int T=S;T;(--T)&=S)
		if(ct[T]&&ct[S^T]) rs+=1ll*S*mrg(T,S^T);
	return printf("%lld\n",rs),0;
}