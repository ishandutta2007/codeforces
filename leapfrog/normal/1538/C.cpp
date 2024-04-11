//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,l,r,a[200005];
inline int get(int i,int L,int R)
{
	int l=lower_bound(a+i+1,a+n+1,L)-a,r=upper_bound(a+i+1,a+n+1,R)-a;
	return max(0,r-l);
}
inline void solve()
{
	read(n),read(l),read(r);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);ll res=0;
	for(int i=1;i<=n;i++) res+=get(i,l-a[i],r-a[i]);
	printf("%lld\n",res);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}