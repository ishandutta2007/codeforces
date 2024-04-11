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
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
const int N=1005;int n,m,Q;
char ch[N][N];ll dp[N][N][2];
inline ll calc(int x,int y)
{
	int rl=0,rr=0,X=x,Y=y;ll rs=0;
	while(!ch[x][y])
	{
		rl++,x--;
		if(ch[x][y]) break;else rl++,y--;
	}x=X,y=Y;
	while(!ch[x][y])
	{
		rr++,y++;
		if(ch[x][y]) break;else rr++,x++;
	}rs+=1ll*rl*rr,x=X,y=Y;
	//printf("gg %d %d\n",rl,rr);
	rl=rr=0;
	while(!ch[x][y])
	{
		rl++,y--;
		if(ch[x][y]) break;else rl++,x--;
	}x=X,y=Y;
	while(!ch[x][y])
	{
		rr++,x++;
		if(ch[x][y]) break;else rr++,y++;
	}
	//printf("gg %d %d\n",rl,rr);
	return rs+1ll*rl*rr-1;
}
int main()
{
	read(n,m,Q);ll rs=0;
	for(int i=0;i<=n+1;i++) ch[i][0]=ch[i][m+1]=1;
	for(int i=0;i<=m+1;i++) ch[0][i]=ch[n+1][i]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		dp[i][j][0]=dp[i-1][j][1]+1,dp[i][j][1]=dp[i][j-1][0]+1;
	//for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",dp[i][j][0],j==m?'\n':' ');
	//for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",dp[i][j][1],j==m?'\n':' ');
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) rs+=dp[i][j][0]+dp[i][j][1]-1;
	for(int x,y;Q--;)
	{
		read(x,y);
		if(ch[x][y]) ch[x][y]=0,rs+=calc(x,y);
		else rs-=calc(x,y),ch[x][y]=1;
		printf("%lld\n",rs);
	}return 0;
}