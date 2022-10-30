//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=10005;int n,m,nx[N];short dp[N][N];char s[N],t[N];
int main()
{
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;i++)
	{
		int vl=0;nx[i]=0;if(s[i]=='.') continue;
		for(int j=i;j<=n;j++) {vl+=(s[j]=='.'?-1:1);if(!vl) {nx[i]=j;break;}}
	}memset(dp,0x3f,sizeof(dp)),dp[1][1]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m+1;j++)
	{
		dp[i+1][j]=min(dp[i][j]+1,(int)dp[i+1][j]);
		if(j<=m&&s[i]==t[j]) dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
		if(s[i]!='.'&&nx[i]) dp[nx[i]+1][j]=min(dp[nx[i]+1][j],dp[i][j]);
	}
	//for(int i=1;i<=n+1;i++) for(int j=1;j<=m+2;j++) printf("%d%c",dp[i][j],j==m+2?'\n':' ');
	return printf("%d\n",dp[n+1][m+1]),0;
}