#include<bits/stdc++.h>
#define Accepted 0 
using namespace std;
const int magic=100;
int n,m,q,a[333333],dp[333333],cur,l[333333];
long long ans;
map<int,int> mp[333333];
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for (int i=0;i<=n;i++) mp[i].clear();
		mp[1][a[1]]=1;
		for (int i=2;i<=n;i++)
		{
			l[i]=mp[i-1][a[i]];
			swap(mp[l[i]-1],mp[i]);
			mp[i][a[i]]=i; 
		}
		for (int i=0;i<=n;i++) dp[i]=0;
		ans=0;
		for (int i=1;i<=n;i++)
		{
			if (!l[i]) continue;
			dp[i]=dp[l[i]-1]+1;
			ans+=dp[i];
		}
		printf("%lld\n",ans);
	}
	return Accepted;
}