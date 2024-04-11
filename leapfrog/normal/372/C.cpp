//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,d,hd,tl,q[150005];ll dp[150005],f[150005];
int main()
{
	read(n),read(m),read(d);
	for(int lt=0,a,b,t;m--;lt=t)
	{
		read(a),read(b),read(t),hd=1,tl=0;int mxd=min(1ll*(t-lt)*d,(ll)n);
		for(int i=1;i<=mxd;q[++tl]=i,i++) while(hd<=tl&&dp[q[tl]]<dp[i]) tl--;
		for(int i=1;i<=n;i++)
		{
			if(i+mxd<=n) {while(hd<=tl&&dp[q[tl]]<dp[i+mxd]) tl--;q[++tl]=i+mxd;}
			for(;q[hd]<i-mxd;hd++);
			f[i]=dp[q[hd]];
		}
		//for(int i=1;i<=n;i++) printf("%lld%c",f[i],i==n?'\n':' ');
		for(int i=1;i<=n;i++) dp[i]=f[i]+b-abs(a-i);
	}
	ll res=-1e18;for(int i=1;i<=n;i++) res=max(res,dp[i]);
	return printf("%lld\n",res),0;
}