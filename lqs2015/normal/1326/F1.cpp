#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,cnt[33333],mp[22][22],sz,arr[22],ct,cc;
vector<long long> dp[33333][16];
long long ans;
char s[22];
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%s",s);
		for (int j=0;j<n;j++)
		{
			mp[i][j]=(s[j]=='1');
		}
	}
	for (int i=0;i<(1<<n);i++) cnt[i]=__builtin_popcount(i);
	for (int i=1;i<(1<<n);i++)
	{
		for (int j=0;j<n;j++)
		{
			dp[i][j].resize((1<<(cnt[i]-1)));
		}
	}
	for (int i=0;i<n;i++)
	{
		dp[1<<i][i][0]=1;
	}
	for (int i=1;i<(1<<n)-1;i++)
	{
		ct=0;
		for (int j=0;j<n;j++)
		{
			if (!(i&(1<<j))) arr[++ct]=j;
		}
		cc=cnt[i]-1;
		for (int j=0;j<n;j++)
		{
			if (!(i&(1<<j))) continue;
			sz=dp[i][j].size();
			for (int k=0;k<sz;k++)
			{
				if (!dp[i][j][k]) continue;
				for (int h=1;h<=ct;h++)
				{
					if (mp[j][arr[h]]) dp[i|(1<<arr[h])][arr[h]][k|(1<<cc)]+=dp[i][j][k];
					else dp[i|(1<<arr[h])][arr[h]][k]+=dp[i][j][k];
				}
			}
		}
	}
	for (int i=0;i<(1<<(n-1));i++)
	{
		ans=0;
		for (int j=0;j<n;j++)
		{
			ans+=dp[(1<<n)-1][j][i];
		}
		printf("%lld ",ans);
	}
	return Accepted;
}