//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,dp[505][505],ls[505],id[26];char c[505];
int main()
{
	read(n),scanf("%s",c+1),memset(dp,0x3f,sizeof(dp));for(int i=1;i<=n;i++) dp[i][i]=1;
	for(int len=1;len<n;len++) for(int i=1,j=i+len;j<=n;i++,j++)
	{
		for(int k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
		if(c[i]==c[j]) dp[i][j]=min(min(dp[i+1][j],dp[i][j-1]),dp[i][j]);
	}
	return printf("%d\n",dp[1][n]),0;
}