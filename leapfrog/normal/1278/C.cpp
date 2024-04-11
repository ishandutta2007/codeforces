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
int n,a[100005],F[400005];
inline void solve()
{
	read(n),memset(F,~0x3f,sizeof(F)),F[200001]=0;int sm=0,rs=0;
	for(int i=1,x;i<=n;i++) {read(x),x=x==2?-1:1,sm+=x,F[sm+200001]=i;if(!sm) rs=max(rs,i);}
	sm=0;for(int i=1;i<=n;i++) read(a[i]),a[i]=a[i]==2?-1:1;
	for(int i=n;i>=1;i--) sm+=a[i],rs=max(rs,n-i+1+F[200001-sm]);
	printf("%d\n",n+n-rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}