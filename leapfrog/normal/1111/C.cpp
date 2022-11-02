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
int n,K,A,B,a[100005];
inline ll solve(int l,int r)
{
	int L=lower_bound(a+1,a+K+1,l)-a,R=upper_bound(a+1,a+K+1,r)-a-1;
	if(L>R) return A;else if(l==r) return B*(R-L+1);
	return min(solve(l,(l+r)>>1)+solve(((l+r)>>1)+1,r),1ll*(R-L+1)*B*(r-l+1));
}
int main()
{
	read(n,K,A,B);for(int i=1;i<=K;i++) read(a[i]);
	return sort(a+1,a+K+1),printf("%lld\n",solve(1,1<<n)),0;
}