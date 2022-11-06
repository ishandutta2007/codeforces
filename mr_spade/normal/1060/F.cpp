#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n;
vector<int> e[N];
double c[N][N];
double dp[N][N],tmp[N],tmp2[N];
int size[N];
void dfs(int x,int father)
{
	register int i,j;
	for(int y:e[x])
		if(y!=father)
			dfs(y,x);
	size[x]=1;dp[x][0]=1;
	for(int y:e[x])
		if(y!=father)
		{
			memset(tmp,0,sizeof(tmp));
			for(i=0;i<=size[y];i++)
			{
				tmp[i]+=dp[y][i];
				for(j=0;j<i;j++)
					tmp[i]+=c[size[y]-1-j][i-1-j]*dp[y][j]/(2*c[i-1][i-1-j]*i);
			}
			memset(tmp2,0,sizeof(tmp2));
			for(i=0;i<size[x];i++)
				for(j=0;j<=size[y];j++)
					tmp2[i+j]+=dp[x][i]*tmp[j];
			memcpy(dp[x],tmp2,sizeof(tmp2));
			size[x]+=size[y];
		}
	return;
}
signed main()
{
	int x,y;
	register int i,j;
	cin>>n;
	for(i=0;i<=n;i++)
	{
		c[i][0]=c[i][i]=1;
		for(j=1;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	for(i=1;i<=n-1;i++)
		cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	for(i=1;i<=n;i++)
	{
		dfs(i,0);
		printf("%.10lf\n",dp[i][n-1]);
		memset(dp,0,sizeof(dp));
	}
	return 0;
}