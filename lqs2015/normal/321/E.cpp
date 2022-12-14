#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[4444][4444],sum[4444][4444],b[4444][4444],dp[888][4444],pos[4444];
const int maxn=1000;
char buffer[maxn],*S,*T;
inline char Get_Char()
{
    if(S==T)
    {
        T=(S=buffer)+fread(buffer,1,maxn,stdin);
        if(S==T) return EOF;
    }
    return *S++;
}
int read()
{
    char c;
    int re=0;
    for(c=Get_Char();c<'0'||c>'9';c=Get_Char());
    while(c>='0'&&c<='9')
           re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();
    return re;
}
int main()
{
	n=read();k=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			b[i][j]=b[i][j-1]+sum[j][j]-sum[j][i-1];
		}
	}
	for (int i=0;i<=k;i++)
	{
		for (int j=0;j<=n;j++)
		dp[i][j]=1e9;
	}
	dp[0][0]=0;pos[n+1]=n;
	for (int i=1;i<=k;i++)
	{
		for (int j=n;j>=1;j--)
		{
			for (int h=pos[j];h<=pos[j+1] && h<j;h++)
			{
				if (dp[i][j]>dp[i-1][h]+b[h+1][j])
				{
					dp[i][j]=dp[i-1][h]+b[h+1][j];
					pos[j]=h;
				}
			}
		}
	}
	printf("%d\n",dp[k][n]);
	return 0;
}