#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2100000;
const ll mod=917120411; 
int n,m;
vector<ll> mp[N],dp1[N],dp2[N];
char s[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=m+5;i++) dp1[0].push_back(0),dp2[0].push_back(0);
	for(int i=1;i<=n+5;i++) dp1[i]=dp1[i-1],dp2[i]=dp2[i-1];
	for(int i=1;i<=n;i++)
	{
		mp[i].push_back(0);
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='.') mp[i].push_back(0);
			else mp[i].push_back(1);
		}
	}
	dp1[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]) continue;
			if(i==1&&j==1) continue;
			dp1[i][j]=(dp1[i-1][j]+dp1[i][j-1])%mod;
		}
	}
	dp2[n][m]=1;
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			if(mp[i][j]) continue;
			if(i==n&&j==m) continue;
			dp2[i][j]=(dp2[i+1][j]+dp2[i][j+1])%mod;
		}
	}
	if(dp1[n][m]==0) return printf("0\n"),0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1) continue;
			if(i==n&&j==m) continue;
			if(mp[i][j]) continue;
			if(dp1[i][j]*dp2[i][j]%mod==dp1[n][m]) return printf("1\n"),0;
		}
	}
	printf("2\n");	
	return 0;
}