#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mx,p,dp[2][500005],ans[500005],a[500005];stack<int>s,ep;
inline void work(int id)
{
	s=ep;
	for(int i=1;i<=n;i++)
	{
		while(!s.empty()&&a[s.top()]>a[i]) s.pop();
		if(s.empty()) ans[i]=0;else ans[i]=s.top();s.push(i);
	}
	for(int i=1;i<=n;i++) dp[id][i]=dp[id][ans[i]]+(i-ans[i])*a[i];
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	work(0),reverse(a+1,a+n+1),work(1),reverse(a+1,a+n+1),reverse(dp[1]+1,dp[1]+n+1);
	for(int i=1;i<=n;i++) if(dp[0][i]+dp[1][i]-a[i]>mx) mx=dp[0][i]+dp[1][i]-a[i],p=i;
	mx=a[p];for(int i=p;i>=1;i--) mx=min(mx,a[i]),ans[i]=mx;
	mx=a[p];for(int i=p;i<=n;i++) mx=min(mx,a[i]),ans[i]=mx;
	for(int i=1;i<=n;i++) printf("%lld%c",ans[i],i==n?'\n':' ');
	return 0;
}