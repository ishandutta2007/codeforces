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
int vl,wh,n,nx[1005],a[1005],m;char st[1005],dp[1005];
int main()
{
	read(n),read(wh);for(int i=1,x;i<=n;i++) read(x),x?nx[x]=i,st[i]=1:0;
	for(int i=1,c,x;i<=n;i++) if(!st[i])
	{
		char tag=(c=0)*(x=i);while(x) c++,(x==wh?tag=1,vl=c:0),x=nx[x];
		if(!tag) a[++m]=c;
	}
	dp[0]=1;for(int i=1;i<=m;i++) for(int j=n;j>=a[i];j--) dp[j]|=dp[j-a[i]];
	for(int i=0;i<=n;i++) if(dp[i]) printf("%d\n",i+vl);
	return 0;
}