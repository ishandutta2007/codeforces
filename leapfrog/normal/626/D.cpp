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
int n,a[2005],mx=-1e9,mn=1e9;double dp[2][10005],f[10005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	double tp=2.0/n/(n-1);for(int i=1;i<=n;i++) mx=max(mx,a[i]),mn=min(mn,a[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		if(a[i]>a[j]) dp[0][a[i]-a[j]]+=tp,dp[1][a[i]-a[j]]+=tp;
	for(int i=1;i<=mx-mn;i++) for(int j=1;j<=mx-mn;j++) f[i+j]+=dp[0][i]*dp[1][j];
	double res=0;for(int i=1;i<=2*(mx-mn);i++) f[i]+=f[i-1];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[j]>a[i]) res+=f[a[j]-a[i]-1]*tp;
	return printf("%.10lf\n",res),0;
}