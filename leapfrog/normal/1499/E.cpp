//Coded by Kamiyama_Shiki on 2021.11.01 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=1005,P=998244353;
int n,m,dp[N][N][2][4];char s[N],t[N];
inline void upd(int &x,int y) {(x+=y)>=P?x-=P:x;}
int main()
{
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++)
	{// i  j 
		dp[i+1][j][0][1]++,dp[i][j+1][1][2]++;
		for(int S=1;S<4;S++)
		{
			if(s[i]!=s[i-1]) upd(dp[i+1][j][0][S|1],dp[i][j][0][S]);
			if(t[j]!=s[i-1]) upd(dp[i][j+1][1][S|2],dp[i][j][0][S]);
			if(s[i]!=t[j-1]) upd(dp[i+1][j][0][S|1],dp[i][j][1][S]);
			if(t[j]!=t[j-1]) upd(dp[i][j+1][1][S|2],dp[i][j][1][S]);
		}
	}
	//for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) printf("<%d,%d>%c",dp[i][j][0],dp[i][j][1],j==m+1?'\n':' ');
	ll rs=0;for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) rs=(rs+dp[i][j][0][3]+dp[i][j][1][3])%P;
	return printf("%lld\n",rs),0;
}