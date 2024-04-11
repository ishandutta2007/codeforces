#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T,typename... A>inline void read(T &t,A &...a) {read(t),read(a...);}
int n,k,a[105];
signed main()
{
	read(n,k);int mx=0,s=0,maxn,minn;
	for(int i=1;i<=n;i++) read(a[i]),mx=max(mx,a[i]);
	for(int i=1;i<=n;i++) s+=mx-a[i];
	maxn=mx+k,minn=mx;if(k>s) k-=s,minn+=k/n+!!(k%n);
	return printf("%d %d\n",minn,maxn),0;
}