#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 998244353
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dp[200005][8][8];
char s[200005];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=7;j++)
		{
			for(int k=0;k<=7;k++)
			{
				//if(dp[i-1][j][k]!=0)printf("%d %d %d %d\n",i-1,j,k,dp[i-1][j][k]);
				for(int now=0;now<=7;now++)
				{
					int nj=0,nk=0;
					if(s[i]=='0')
					{
						if((j&1)==0&&(now&1)==1)continue;
						if((j&1)==1)nj|=1;
						if((j&2)==0&&(now&2)==2)continue;
						if((j&2)==2)nj|=2;
						if((j&4)==0&&(now&4)==4)continue;
						if((j&4)==4)nj|=4;
					}
					else
					{
						if((j&1)==0&&(now&1)==0)nj|=1;
						if((j&1)==1)nj|=1;
						if((j&2)==0&&(now&2)==0)nj|=2;
						if((j&2)==2)nj|=2;
						if((j&4)==0&&(now&4)==0)nj|=4;
						if((j&4)==4)nj|=4;
					}
					nk=k;
					if(now==1||now==6)nk|=1;
					if(now==2||now==5)nk|=2;
					if(now==4||now==3)nk|=4;
					dp[i][nj][nk]=(dp[i][nj][nk]+dp[i-1][j][k])%mod; 
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=7;i++)ans=(ans+dp[n][i][7])%mod;
	printf("%d\n",ans);
	return 0;
}