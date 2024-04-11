#include<bits/stdc++.h>
using namespace std;
const int N=300;
map<int,int> dp;
int n;
int l[N+5],c[N+5];
void checkmin(int x,int y)
{
	if(dp.find(x)==dp.end())
	{
		dp[x]=y;
		return;
	}
	dp[x]=min(dp[x],y);
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&l[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
	{
		checkmin(l[i],c[i]);
		map<int,int>::iterator it;
		for(it=dp.begin();it!=dp.end();it++)
		{
			int ll=it->first,cc=it->second;
			checkmin(__gcd(ll,l[i]),c[i]+dp[ll]);
		}
	}
	if(dp.find(1)==dp.end()) printf("-1\n");
	else printf("%d\n",dp[1]);
	return 0;
}