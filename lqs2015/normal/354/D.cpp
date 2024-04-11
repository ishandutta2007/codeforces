#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int n,k,x,y,pre[1111],dp[1111],dpp[1111],mx,num[1111],ans;
vector<int> c[111111];
int main()
{
//	freopen("cin.in","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		c[y].push_back(n-x+1);
	}
	for (int i=0;i<=maxn+1;i++) dpp[i]=-1e9;
	dpp[0]=0;
	for (int i=1;i<=n;i++)
	{
		mx=min(maxn,n-i+1);
		pre[0]=dpp[0];
		for (int j=1;j<=mx;j++) pre[j]=max(pre[j-1],dpp[j]);
		memset(num,0,sizeof(num));
		for (int j=0;j<c[i].size();j++)
		{
			if (c[i][j]<=mx) num[c[i][j]]++;
		}
		for (int j=1;j<=mx;j++) num[j]+=num[j-1];
		dp[0]=max(dpp[0],dpp[1]);
		for (int j=1;j<=mx;j++)
		{
			dp[j]=max(dpp[j+1],pre[j]-(j+1)*j/2-2)+3*num[j];
		} 
		for (int j=0;j<=mx;j++) dpp[j]=dp[j];
	}
	for (int i=0;i<=mx;i++) ans=max(ans,dp[i]);
	printf("%d\n",3*k-ans);
	return 0;
}