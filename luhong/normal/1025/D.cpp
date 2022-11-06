#include<iostream>
#include<cstdio>
using namespace std;
bool ok[705][705];
bool dp[705][705][2];
int a[705];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n+1;i++)dp[i][i-1][0]=dp[i][i-1][1]=1; 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ok[i][j]=gcd(a[i],a[j])==1?0:1;
	for(int len=1;len<=n;len++)
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			for(int root=l;root<=r;root++)
			{
				dp[l][r][0]|=dp[l][root-1][1]&dp[root+1][r][0]&ok[root][l-1];
				dp[l][r][1]|=dp[l][root-1][1]&dp[root+1][r][0]&ok[root][r+1];
			}
		}
	bool ans=0;
	for(int i=1;i<=n;i++)ans|=dp[1][i-1][1]&dp[i+1][n][0];
	if(ans)puts("Yes");else puts("No");
	return 0;
}