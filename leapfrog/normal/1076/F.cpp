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
int n,K,fx[300005],fy[300005],dx[300005],dy[300005];
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(dx[i]);
	for(int i=1;i<=n;i++) read(dy[i]);
	for(int i=1;i<=n;i++) fx[i]=max(0ll,dx[i]-1ll*K*dy[i]+fx[i-1]),fy[i]=max(0ll,dy[i]-1ll*K*dx[i]+fy[i-1]);
	for(int i=1;i<=n;i++) if(fx[i]>K||fy[i]>K) return puts("NO"),0;
	return puts("YES"),0;
}