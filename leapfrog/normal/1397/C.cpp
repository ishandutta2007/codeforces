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
int n;ll a[100005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	if(n==1)
	{
		printf("1 1\n-114514\n");
		printf("1 1\n114514\n");
		printf("1 1\n%lld\n",-a[1]);
		return 0;
	}
	printf("%d %d\n",1,n);
	for(int i=1;i<=n;i++) printf("%lld%c",-1ll*a[i]*n,i==n?'\n':' ');
	printf("%d %d\n",1,n-1);
	for(int i=1;i<n;i++) printf("%lld%c",1ll*a[i]*(n-1),i==n-1?'\n':' ');
	return printf("%d %d\n%lld\n",n,n,a[n]*(n-1ll)),0;
}