#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int mod=51123987;
int n,nxt[222][6],dp[155][55][55][55],ans;
char s[222];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	nxt[n][0]=nxt[n][1]=nxt[n][2]=n;
	for (int i=n-1;i>=0;i--)
	{
		for (int j=0;j<3;j++) nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i]-'a']=i;
	}
	dp[0][0][0][0]=1;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=51;j++)
		{
			for (int k=0;k<=51;k++)
			{
				for (int h=0;h<=51;h++)
				{
					if (!dp[i][j][k][h]) continue;
					if (j+k+h==n && abs(j-k)<=1 && abs(h-k)<=1 && abs(h-j)<=1) ans=(ans+dp[i][j][k][h])%mod;
					dp[nxt[i][0]][j+1][k][h]=(dp[nxt[i][0]][j+1][k][h]+dp[i][j][k][h])%mod;
					dp[nxt[i][1]][j][k+1][h]=(dp[nxt[i][1]][j][k+1][h]+dp[i][j][k][h])%mod;
					dp[nxt[i][2]][j][k][h+1]=(dp[nxt[i][2]][j][k][h+1]+dp[i][j][k][h])%mod;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}