#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,k,msk[11],mk,dist[2222][11],dp[2222][2222],lst;
char s[11];
int main()
{
	scanf("%d%d",&n,&k);
	msk[0]=(1<<7)-1-(1<<3);msk[1]=(1<<2)+(1<<5);msk[2]=(1<<7)-1-(1<<1)-(1<<5);
	msk[3]=(1<<7)-1-(1<<1)-(1<<4);msk[4]=(1<<7)-1-(1<<0)-(1<<4)-(1<<6);
	msk[5]=(1<<7)-1-(1<<2)-(1<<4);msk[6]=(1<<7)-1-(1<<2);msk[7]=(1<<0)+(1<<2)+(1<<5);
	msk[8]=(1<<7)-1;msk[9]=(1<<7)-1-(1<<4);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);mk=0;
		for (int j=0;j<7;j++)
		{
			if (s[j]=='1') mk+=(1<<j);
		}
		for (int j=0;j<=9;j++)
		{
			if ((msk[j]&mk)==mk) dist[i][j]=__builtin_popcount(msk[j]^mk);
			else dist[i][j]=k+1;
		}
	}
	dp[n+1][0]=1;
	for (int i=n+1;i>1;i--)
	{
		for (int j=0;j<=k;j++)
		{
			if (!dp[i][j]) continue;
			for (int h=0;h<=9;h++)
			{
				if (j+dist[i-1][h]<=k) dp[i-1][j+dist[i-1][h]]=1;
			}
		}
	}
	lst=k;
	if (!dp[1][k])
	{
		printf("-1\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=9;j>=0;j--)
		{
			if (k<dist[i][j]) continue;
			if (dp[i+1][k-dist[i][j]]) 
			{
				printf("%d",j);
				k-=dist[i][j];
				break;
			}
		}
	}
	printf("\n");
	return Accepted;
}