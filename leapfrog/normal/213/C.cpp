//
#include<bits/stdc++.h>
using namespace std;const long long P=998244353;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[305][305],dp[605][305][305];
int main()
{
	read(n),memset(dp,~0x3f,sizeof(dp));
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) read(a[i][j]);
	if(n==1) return printf("%d\n",a[1][1]),0;else dp[2][1][1]=a[1][1];
	for(int s=3;s<=n+n;s++)
		for(int i=1;i<=n&&i<s;i++)
			for(int j=i;j<=n&&j<s;j++)
			{
				int x1=i,x2=j,y1=s-i,y2=s-j;if(y1>n||y2>n) continue;
				dp[s][i][j]=max(max(dp[s-1][i][j],dp[s-1][i][j-1]),max(dp[s-1][i-1][j],dp[s-1][i-1][j-1]));
				if(x1^x2) dp[s][i][j]+=a[x1][y1]+a[x2][y2];else dp[s][i][j]+=a[x1][y1];
			}
	return printf("%d\n",dp[n<<1][n][n]),0;
}