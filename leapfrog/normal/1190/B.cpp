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
int T,n,a[100005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);int tag=0,cnt=0,sm;a[0]=-1;
	for(int i=2;i<=n;i++) if(a[i]==a[i-1]&&++cnt&&a[i]-a[i-2]<=1) {tag=1;break;}
	if(tag||cnt>=2) return puts("cslnb"),0;else sm=n;
	for(int i=1;i<=n;i++) sm+=a[i]-i;
	if(sm&1) puts("sjfnb");else puts("cslnb");
	return 0;
}