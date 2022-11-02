//
//
#include<bits/stdc++.h>
using namespace std;const double eps=1e-8;
template<typename T>inline void read(T &x)
{
	x=0;register char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int a,b,c;double dp[105][105][105][3];
inline void dfs(int a,int b,int c)
{
	if(!a&&!b) return(void)(dp[a][b][c][2]=1);
	if(!a&&!c) return(void)(dp[a][b][c][1]=1);
	if(!b&&!c) return(void)(dp[a][b][c][0]=1);
	if(dp[a][b][c][0]>eps||dp[a][b][c][1]>eps||dp[a][b][c][2]>eps) return;
	if(a) {dfs(a-1,b,c);for(int i=2;~i;i--) dp[a][b][c][i]+=dp[a-1][b][c][i]*1.0*a*c/(a*c+a*b+b*c);}
	if(b) {dfs(a,b-1,c);for(int i=2;~i;i--) dp[a][b][c][i]+=dp[a][b-1][c][i]*1.0*a*b/(a*c+a*b+b*c);}
	if(c) {dfs(a,b,c-1);for(int i=2;~i;i--) dp[a][b][c][i]+=dp[a][b][c-1][i]*1.0*b*c/(a*c+a*b+b*c);}
}
int main()
{
	read(a),read(b),read(c),dfs(a,b,c);
	return printf("%.15lf %.15lf %.15lf\n",dp[a][b][c][0],dp[a][b][c][1],dp[a][b][c][2]),0;
}