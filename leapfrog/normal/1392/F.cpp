//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n;ll sm,a[1000005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),sm+=a[i];
	sm-=1ll*n*(n-1)/2;int rs=sm%n;ll w=sm/n;for(int i=1;rs;i++,rs--) a[i]=-1;
	for(int i=1;i<=n;i++) if(~a[i]) printf("%lld ",w+i-1);else printf("%lld ",w+i);
	return putchar('\n'),0;
}