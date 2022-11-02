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
int n,A,B;
int main()
{
	read(n,A,B);for(int i=1;i<=n;i++)
	{
		int x;read(x);ll v=1ll*x*A/B;
		ll q=1ll*v*B,w=(q+A-1)/A;//w>=ceil(v*B/A)
		printf("%lld%c",x-w,i==n?'\n':' ');
	}return 0;
}