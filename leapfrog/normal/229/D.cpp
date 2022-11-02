#include<cstdio>
#include<cstring>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,s[5005],a[5005],dp[5005][5005];
inline int min(int a,int b) {return a<b?a:b;}
int main()
{
	read(n),memset(dp,0x3f,sizeof(dp)),dp[1][1]=dp[1][0]=dp[0][0]=0;int res=1e9;
	for(int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++) for(int j=i,l=i;j;j--)
	{
		if(!l) dp[j][i]=min(dp[j][i],dp[1][j-1]+i-j);
		while(l&&s[j-1]-s[l-1]<=s[i]-s[j-1]) dp[j][i]=min(dp[j][i],dp[l][j-1]+i-j),l--;
	}
	for(int j=1;j<=n;j++) res=min(res,dp[j][n]);
	return printf("%d\n",res),0;
}