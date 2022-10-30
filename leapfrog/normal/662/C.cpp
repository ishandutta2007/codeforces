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
int n,m;ll sz[1<<20|5],tt[1<<20|5];char ch[21][100005];
inline void FWT(int n,ll *a)
{
	for(int d=1;d<n;d<<=1) for(int l=0;l<n;l+=d+d)
		for(int p=l;p<(l|d);p++) {ll x=a[p],y=a[p+d];a[p]=x+y,a[p+d]=x-y;}
}
inline void IFWT(int n,ll *a)
{
	for(int d=1;d<n;d<<=1) for(int l=0;l<n;l+=d+d)
		for(int p=l;p<(l|d);p++) {ll x=a[p],y=a[p+d];a[p]=(x+y)/2,a[p+d]=(x-y)/2;}
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int j=1;j<=m;j++) {int r=0;for(int i=1;i<=n;i++) r=r<<1|(ch[i][j]^48);tt[r]++;}
	n=1<<n;for(int i=1;i<n;i++) sz[i]=sz[i>>1]+(i&1);
	for(int i=0;i<n;i++) sz[i]=min(sz[i],sz[(n-1)^i]);
	FWT(n,tt),FWT(n,sz);for(int i=0;i<n;i++) sz[i]*=tt[i];
	IFWT(n,sz);ll rs=1e18;for(int i=0;i<n;i++) rs=min(rs,sz[i]);
	return printf("%lld\n",rs),0;
}