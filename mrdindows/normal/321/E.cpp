#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)4010)
#define K ((ll)810)
#define INF ((ll)1e9)

ll n,k,sum[N][N],dp[2][N],update[2][N];

int main()
{
	cin>>n>>k;
	getchar();
	for(int i=1;i<=n;i++) {
	    char s[8080];
	    gets(s);
		for(int j=1;j<=n;j++)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1] + s[2 * j - 2] - '0';
	}
	dp[1][0]=INF;
	update[0][n+1]=update[1][n+1]=n;
	for(int i=1;i<=n;i++)dp[1][i]=sum[i][i];
	for(int j=2;j<=k;j++)
		for(int i=n;i>=j;i--)
		{
			bool p=(j&1);
			dp[p][i]=INF;
			for(int k=max(update[!p][i],j-1);k<=min(update[p][i+1],i-1);k++)
			{
				ll num=dp[!p][k]+sum[i][i]-sum[i][k]-sum[k][i]+sum[k][k];
				if(num<dp[p][i])dp[p][i]=num,update[p][i]=k;
			}
		}
	cout<<dp[(k&1)][n]/2<<"\n";
	return 0;
}