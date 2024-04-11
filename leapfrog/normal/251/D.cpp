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
int n,tot,ps[65];ll a[100005],xr=0;char rs[100005];bitset<100005>f[65];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),xr^=a[i];
	for(int k=0;k<2;k++) for(int i=61;~i;i--) if(((xr>>i)&1)==k)
	{
		tot++;for(int j=1;j<=n;j++) if((a[j]>>i)&1) f[tot][j]=1;
		f[tot][n+1]=k^1;for(int j=1;j<tot;j++) if(f[tot][ps[j]]) f[tot]^=f[j];
		ps[tot]=0;for(int j=1;j<=n;j++) if(f[tot][j]) {ps[tot]=j;break;}
		if(!ps[tot]) tot--;else for(int j=1;j<tot;j++) if(f[j][ps[tot]]) f[j]^=f[tot];
	}
	for(int i=0;i<62;i++) rs[ps[i]]=f[i][n+1];
	for(int i=1;i<=n;i++) printf("%d%c",2-rs[i],i==n?'\n':' ');
	return 0;
}