#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,dp[222222][5],path[222222][5],cur,x,y;
char s[222222],c1,c2;
vector<int> ans;
int nxt(int x,char c)
{
	if (!x)
	{
		if (c=='t') return 1;
		if (c=='o') return 2;
		return 0;
	}
	if (x==1)
	{
		if (c=='w') return 3;
		if (c=='t') return 1;
		if (c=='o') return 2;
		return 0; 
	}
	if (x==2)
	{
		if (c=='n') return 4; 
		if (c=='t') return 1;
		if (c=='o') return 2;
		return 0;
	}
	if (x==3)
	{
		if (c=='o') return -1;
		if (c=='t') return 1;
		return 0;
	}
	if (c=='e') return -1;
	if (c=='o') return 2;
	if (c=='t') return 1;
	return 0;
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",s);
		n=strlen(s);
		for (int i=0;i<=n;i++)
		{
			for (int j=0;j<5;j++)
			{
				dp[i][j]=1e9;
				path[i][j]=-1;
			}
		}
		dp[0][0]=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<5;j++)
			{
				if (dp[i][j]>1e8) continue;
				if (nxt(j,s[i])!=-1) 
				{
					if (dp[i+1][nxt(j,s[i])]>dp[i][j])
					{
						dp[i+1][nxt(j,s[i])]=dp[i][j];
						path[i+1][nxt(j,s[i])]=j;
					}
				}
				if (dp[i+1][j]>dp[i][j]+1)
				{
					dp[i+1][j]=dp[i][j]+1;
					path[i+1][j]=-1;
				}
			}
		}
		cur=0;
		for (int j=1;j<5;j++)
		{
			if (dp[n][j]<dp[n][cur]) cur=j;
		}
		printf("%d\n",dp[n][cur]);
		x=n;y=cur;
		while(x)
		{
			if (!~path[x][y]) printf("%d ",x);
			else y=path[x][y];
			x--;
		}
		printf("\n");
	}
	return Accepted;
}