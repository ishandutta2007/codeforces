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
int n,a[100005];long long r=0;
int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) r+=1ll*a[i]*(n-a[i]+1);
	for(int i=1;i<n;i++) r-=1ll*min(a[i],a[i+1])*(n-max(a[i],a[i+1])+1);
	return printf("%lld\n",r),0;
}