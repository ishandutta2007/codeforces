#include<bits/stdc++.h>
using namespace std;
char s[111111];
int n,id[15][15][15],cnt,edge[11111][11],dp[11111],a,b,c,fuck,ddp[11111];
long long ans;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<11;i++)
	{
		for (int j=0;j<11;j++)
		{
			for (int k=0;k<11;k++)
			{
				id[i][j][k]=++cnt;
			}
		}
	}
	for (int i=0;i<11;i++)
	{
		for (int j=0;j<11;j++)
		{
			for (int k=0;k<11;k++)
			{
				for (int h=0;h<i;h++)
				{
					b=h+1;fuck=i-1;
					for (int p=0;p<(j+10)%11;p++)
					{
						b+=fuck;
						fuck--;
					}
					b=(b%11+11)%11;
					c=i-h-1;fuck=i+1;
					for (int p=1;p<=k;p++)
					{
						c+=fuck;
						fuck++;
					}
					c=(c%11+11)%11;
					a=(i+k+b)%11;
					edge[id[i][j][k]][h]=id[a][b][c];
				}
			}
		}
	}
	for (int i=n-1;i>=0;i--)
	{
		int g=s[i]-'0';
		if (g) ans+=(dp[id[g][g][9-g]]+1);
		for (int j=1;j<=cnt;j++)
		{
			if (!edge[j][g]) ddp[j]=0;
			else ddp[j]=dp[edge[j][g]]+1;
		}
		memcpy(dp,ddp,sizeof(dp));
	}
	printf("%lld\n",ans);
	return 0;
}