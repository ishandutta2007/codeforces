#include <bits/stdc++.h>
using namespace std;
int n;
string s,t;
bool vis[2005][2005];
int pre[26][2005],cum[2][26][2005],dp[2005][2005];
int solve(int idx,int mex)
{
	if (idx<0)
	return 0;
	if (vis[idx][mex])
	return dp[idx][mex];
	vis[idx][mex]=1;
	int tmp=pre[t[idx]-'a'][mex];
	if (tmp!=-1)
	dp[idx][mex]=min(dp[idx][mex],solve(idx-1,tmp));
	if (cum[1][t[idx]-'a'][n]-cum[1][t[idx]-'a'][idx]<=cum[0][t[idx]-'a'][n]-cum[0][t[idx]-'a'][mex])
	dp[idx][mex]=min(dp[idx][mex],solve(idx-1,mex)+1);
	return dp[idx][mex];
}
int main()
{
	int tt;
	cin >> tt;
	while (tt--)
	{
		cin >> n >> s >> t;
		for (int i=0;i<=n;i++)
		{
			for (int j=0;j<26;j++)
			{
				if (!i)
				pre[j][i]=-1;
				else
				pre[j][i]=pre[j][i-1];
				cum[0][j][i+1]=cum[0][j][i];
				cum[1][j][i+1]=cum[1][j][i];
			}
			if (i)
			pre[s[i-1]-'a'][i]=i-1;
			if (i!=n)
			{
				cum[0][s[i]-'a'][i+1]++;
				cum[1][t[i]-'a'][i+1]++;
			}
			for (int j=0;j<=n;j++)
			{
				dp[i][j]=n+1;
				vis[i][j]=0;
			}
		}
		int ans=solve(n-1,n);
		if (ans>n)
		ans=-1;
		cout << ans << endl;
	}
}