#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
char s[2222];
const long long mod=1e6+3;
int m,n,t,a[2222],st[2222],x[2222],y[2222],dp[2222][2222];
long long sum;
int main()
{
	//freopen("cin.in","r",stdin);
	gets(s);
	int sz=strlen(s);
	for (int i=0;i<sz-1;i++)
	{
		if ((s[i]<'0' || s[i]>'9') && (s[i+1]=='*' || s[i+1]=='/')) 
		{
			printf("0\n");
			return 0;
		}
	}
	for (int i=0;i<sz;i++)
	{
		if (s[i]<'0' || s[i]>'9') t++;
		else if (t || i==0)
		{
			a[m]=t-1;
			m++;
			t=0;
		}
	}
	if (t || (s[0]=='*' || s[0]=='/'))
	{
		printf("0\n");
		return 0;
	}
	a[0]++;
	for (int i=0;i<m;i++)
	{
		st[i]=n;
		for (int j=a[i];j>=0;j--)
		{
			x[n]=i;
			y[n]=j;
			n++;
		}
	}
	for (int i=n-1;i>=0;i--)
	{
		dp[i][x[i]]=1;
		for (int j=x[i]+1;j<m;j++)
		{
			if (y[i]>0) dp[i][j]=dp[i+1][j];
			else dp[i][j]=0;
			sum=0;
			for (int k=x[i];k<j;k++)
			{
				sum+=(long long)dp[i][k]*dp[st[k+1]][j];
			}
			dp[i][j]=(dp[i][j]+sum)%mod;
		}
	}
	printf("%d\n",dp[0][m-1]);
	return 0;
}