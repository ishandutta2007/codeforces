//
//
#include<bits/stdc++.h>
using namespace std;const int X=303;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,d,m,a[30005],dp[30005][305<<1];
int main()
{
	read(n),read(d),m=0;int res=0;
	for(int i=1,x;i<=n;i++) read(x),m=max(m,x),++a[x];
	memset(dp,~0x3f,sizeof(dp)),dp[d][X]=res=a[d]+a[0];
	for(int i=d+1;i<=m;i++) for(int o=-300;o<=300;o++)
	{
		if(d+o>0&&d+o<=i) dp[i][o+X]=max(dp[i][o+X],dp[i-o-d][o+X]);
		if(d+o>0&&d+o<=i) dp[i][o+X]=max(dp[i][o+X],dp[i-o-d][o+X-1]);
		if(d+o>0&&d+o<=i) dp[i][o+X]=max(dp[i][o+X],dp[i-o-d][o+X+1]);
		dp[i][o+X]+=a[i],res=max(res,dp[i][o+X]);
	}
	return printf("%d\n",res),0;
}