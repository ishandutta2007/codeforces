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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int n,K,dp[1005][2005][4];const int P=998244353;
inline int f(int x,int y,int w) {return x>=1&&y>=1?dp[x][y][w]:0;}
template<typename T>inline void zy(T &x,T y) {(x+=y)>=P?x-=P:x;}
template<typename T,typename...L>inline void zy(T &x,T y,L...l) {zy(x,y),zy(x,l...);}
int main()
{
	read(n,K),dp[1][1][0]=dp[1][1][3]=dp[1][2][1]=dp[1][2][2]=1;
	for(int i=2;i<=n;i++) for(int j=1;j<=K;j++)
		zy(dp[i][j][0],f(i-1,j,0),f(i-1,j,1),f(i-1,j,2),f(i-1,j-1,3)),
		zy(dp[i][j][1],f(i-1,j-1,0),f(i-1,j,1),f(i-1,j-2,2),f(i-1,j-1,3)),
		zy(dp[i][j][2],f(i-1,j-1,0),f(i-1,j-2,1),f(i-1,j,2),f(i-1,j-1,3)),
		zy(dp[i][j][3],f(i-1,j-1,0),f(i-1,j,1),f(i-1,j,2),f(i-1,j,3));
	int rs=0;zy(rs,dp[n][K][0],dp[n][K][1],dp[n][K][2],dp[n][K][3]);
	return printf("%d\n",rs),0;
}