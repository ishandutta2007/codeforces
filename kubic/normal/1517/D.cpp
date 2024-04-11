#include <bits/stdc++.h>
using namespace std;
#define N 505
#define M 15
#define N1 3000005
#define pb push_back
#define set(a,vl) memset(a,vl,sizeof(a))
int n,m,c,a1[N][N],a2[N][N],dp[M][N][N];
void W(int &x,int y) {x=min(x,y);}
int main()
{
	scanf("%d %d %d",&n,&m,&c);
	if(c&1)
	{
		for(int i=1;i<=n;++i,puts(""))
			for(int j=1;j<=m;++j) printf("-1 ");return 0;
	}c/=2;
	for(int i=1;i<=n;++i) for(int j=1;j<m;++j) scanf("%d",&a1[i][j]);
	for(int i=1;i<n;++i) for(int j=1;j<=m;++j) scanf("%d",&a2[i][j]);
	for(int i=1;i<=c;++i)
	{
		for(int x=1;x<=n;++x) for(int y=1;y<=m;++y)
		{
			dp[i][x][y]=1e9;
			if(x>1) W(dp[i][x][y],dp[i-1][x-1][y]+a2[x-1][y]);
			if(y>1) W(dp[i][x][y],dp[i-1][x][y-1]+a1[x][y-1]);
			if(x<n) W(dp[i][x][y],dp[i-1][x+1][y]+a2[x][y]);
			if(y<m) W(dp[i][x][y],dp[i-1][x][y+1]+a1[x][y]);
		}
	}
	for(int i=1;i<=n;++i,puts("")) for(int j=1;j<=m;++j)
		printf("%d ",dp[c][i][j]*2);return 0;
}