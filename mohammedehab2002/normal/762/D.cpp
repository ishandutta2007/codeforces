#include <iostream>
using namespace std;
int n,arr[3][100005];
long long dp[3][100005][8];
bool vis[3][100005][8];
long long solve(int x,int y,int mask)
{
	if (y==n-1 && x==2)
	return arr[x][y];
	if (y>=n)
	return -(1LL<<60);
	if (vis[x][y][mask])
	return dp[x][y][mask];
	vis[x][y][mask]=1;
	long long ans=solve(x,y+1,(1<<x));
	if (x && !(mask&(1<<(x-1))))
	ans=max(ans,solve(x-1,y,(mask|(1<<(x-1)))));
	if (x!=2 && !(mask&(1<<(x+1))))
	ans=max(ans,solve(x+1,y,(mask|(1<<(x+1)))));
	if (!x && mask==1)
	ans=max(ans,solve(2,y+1,7)+arr[0][y+1]+arr[1][y+1]+arr[1][y]+arr[2][y]);
	if (x==2 && mask==4)
	ans=max(ans,solve(0,y+1,7)+arr[2][y+1]+arr[1][y+1]+arr[1][y]+arr[0][y]);
	return dp[x][y][mask]=ans+arr[x][y];
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<3;i++)
	{
		for (int x=0;x<n;x++)
		scanf("%d",&arr[i][x]);
	}
	printf("%I64d",solve(0,0,1));
}