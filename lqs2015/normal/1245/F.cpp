#include<bits/stdc++.h>
using namespace std;
int test,l,r,nj,nk;
long long dp[44][2][2],res;
long long solve(int r1,int r2)
{
	if (r1<0 || r2<0) return 0;
	memset(dp,0,sizeof(dp));
	dp[30][0][0]=1;
	for (int i=30;i>0;i--)
	{
		for (int j=0;j<2;j++)
		{
			for (int k=0;k<2;k++)
			{
				if (!dp[i][j][k]) continue;
				for (int h=0;h<2;h++)
				{
					for (int p=0;p<2;p++)
					{
						if (h+p==2) continue;
						if (!j && h==1 && !(r1&(1<<(i-1)))) continue;
						if (!k && p==1 && !(r2&(1<<(i-1)))) continue;
						nj=j;nk=k;
						if (!h && (r1&(1<<(i-1)))) nj=1;
						if (!p && (r2&(1<<(i-1)))) nk=1;
						dp[i-1][nj][nk]+=dp[i][j][k];
					}
				}
			}
		}
	}
	res=dp[0][0][0]+dp[0][0][1]+dp[0][1][0]+dp[0][1][1];
	return res;
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&l,&r);
		printf("%lld\n",solve(r,r)-solve(l-1,r)-solve(r,l-1)+solve(l-1,l-1));
	}
	return 0;
}