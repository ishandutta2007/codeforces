#include<bits/stdc++.h>
#define inf 1000000000
#define N 85
using namespace std;

int n,cnt,m,dp[N][N][N][2],a[N][N];
int solve(int x,int y,int z,int p){
	if (dp[x][y][z][p]!=-1) return dp[x][y][z][p];
	int &ans=dp[x][y][z][p],i; ans=inf;
	if (!p)
		for (i=x+1; i<=y; i++) ans=min(ans,a[x][i]+min(solve(x+1,i,z-1,1),solve(i,y,z-1,0)));
	else
		for (i=x; i<y; i++) ans=min(ans,a[y][i]+min(solve(x,i,z-1,1),solve(i,y-1,z-1,0)));
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&cnt,&m);
	int i,j,x,y,z;
	memset(a,60,sizeof(a));
	for (i=1; i<=m; i++){
		scanf("%d%d%d",&x,&y,&z); a[x][y]=min(a[x][y],z);
	}
	memset(dp,-1,sizeof(dp));
	for (i=1; i<=n; i++)
		for (j=i; j<=n; j++) dp[i][j][1][0]=dp[i][j][1][1]=0;
	int ans=inf;
	for (i=1; i<=n; i++)
		for (j=i; j<=n; j++) ans=min(ans,min(solve(i,j,cnt,0),solve(i,j,cnt,1)));
	printf("%d\n",(ans<inf)?ans:-1);
	return 0;
}