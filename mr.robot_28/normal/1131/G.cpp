#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=250050,M=1e7+5;
vector<int>v1[N],v2[N];
int n,m,t,v,tt,k[N],l[M],h[M],s[M];ll mn[M],c[M],dp[M];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=k[i];j;j--)scanf("%d",&v),v1[i].push_back(v);
		for(int j=k[i];j;j--)scanf("%d",&v),v2[i].push_back(v);
	}
	int q,id,mul;scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&id,&mul);
		for(int j=0;j<k[id];j++){++tt;h[tt]=v1[id][j];c[tt]=1ll*v2[id][j]*mul;}
	}
	for(int i=m;i>=1;s[++t]=i,i--)while(t&&i<=s[t]-h[s[t]])l[s[t--]]=i+1;
	while(t)l[s[t--]]=1;mn[0]=1e18;
	for(int i=1;i<=m;i++)
	{
		while(t&&i>=s[t]+h[s[t]])t--;
		dp[i]=min(dp[l[i]-1]+c[i],mn[t]);
		s[++t]=i;mn[t]=min(mn[t-1],dp[i-1]+c[i]);
	}
	printf("%lld\n",dp[m]);
	return 0;
}