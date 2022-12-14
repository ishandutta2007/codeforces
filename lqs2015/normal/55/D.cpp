#include<bits/stdc++.h>
using namespace std;
long long t,arr[22],cnt,dp[2][2][2520][50],nj,nk,nh,la,nw,ng,id[5555],ar[111],lc[111][11],ct;
long long l,r,ans;
long long solve(long long x)
{
	ct=0;
	while(x)
	{
		arr[++ct]=x%10;
		x/=10;
	}
	la=0;nw=1;
	memset(dp[la],0,sizeof(dp[la]));
	dp[la][0][0][1]=1;
	for (int i=ct;i>=1;i--)
	{
		memset(dp[nw],0,sizeof(dp[nw]));
		for (int j=0;j<2;j++)
		{
			for (int k=0;k<2520;k++)
			{
				for (int h=1;h<=cnt;h++)
				{
					if (!dp[la][j][k][h]) continue;
					for (int p=0;p<=9;p++)
					{
						if (!j && p>arr[i]) break;
						if (!j && p==arr[i]) nj=0;
						else nj=1;
						nk=(k*10+p)%2520;
						nh=lc[h][p];
						dp[nw][nj][nk][nh]+=dp[la][j][k][h];
					}
				}
			}
		}
		la^=1;nw^=1;
	}
	ans=0;
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2520;j++)
		{
			for (int k=1;k<=cnt;k++)
			{
				if (j%ar[k]==0)
				{
					ans+=dp[la][i][j][k];
				}
			}
		}
	}
	return ans;
}
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}
void Init()
{
	int x=sqrt(2520);
	for (int i=1;i<=x;i++)
	{
		if (2520%i==0)
		{
			++cnt;ar[cnt]=i;
			id[i]=cnt;
			++cnt;ar[cnt]=2520/i;
			id[2520/i]=cnt;
		}
	}
	for (int i=1;i<=cnt;i++)
	{
		lc[i][0]=lc[i][1]=i;
		for (int j=2;j<=9;j++)
		{
			lc[i][j]=id[lcm(ar[i],j)];
		}
	}
}
int main()
{
	scanf("%lld",&t);
	Init();
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}