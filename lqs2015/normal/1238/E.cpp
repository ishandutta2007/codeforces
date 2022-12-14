#include<bits/stdc++.h>
using namespace std;
int n,m,num[22][1111111],fun[1111111];
int a[22][22],dp[1111111],x;
char s[111111];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for (int i=0;i<n-1;i++)
	{
		a[s[i]-'a'][s[i+1]-'a']++;
		a[s[i+1]-'a'][s[i]-'a']++;
	}	
	for (int i=0;i<m;i++) fun[1<<i]=i;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<(1<<m);j++)
		{
			num[i][j]=num[i][j-(j&(-j))]+a[fun[j&(-j)]][i];
		}
	}
	dp[0]=0;
	for (int i=1;i<(1<<m);i++) dp[i]=1e9;
	for (int i=0;i<(1<<m)-1;i++)
	{
		x=__builtin_popcount(i)+1;
		for (int j=0;j<m;j++)
		{
			if (i&(1<<j)) continue;
			dp[i^(1<<j)]=min(dp[i^(1<<j)],dp[i]+x*num[j][i]-x*num[j][(1<<m)-1-i-(1<<j)]);
		}
	}
	printf("%d\n",dp[(1<<m)-1]);
	return 0;
}