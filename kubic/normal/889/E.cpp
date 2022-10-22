#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define pb push_back
int n;ll a[N];priority_queue<ll> q;
map<ll,ll> dp;vector<ll> vc[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{scanf("%lld",&a[i]);if(i>1) a[i]=min(a[i],a[i-1]);}
	for(int i=1;i<=n;++i)
	{
		while(!q.empty())
		{
			ll t=q.top();if(t<a[i]) break;q.pop();
			vc[i].pb(t);q.push(t%a[i]);
		}q.push(a[i]-1);
	}while(!q.empty()) {ll t=q.top();q.pop();dp[t]=t*n;}
	for(int i=n;i;--i) for(auto j:vc[i])
		dp[j]=max(dp[a[i]-1]-a[i]*(i-1),dp[j%a[i]])+j/a[i]*a[i]*(i-1);
	printf("%lld\n",dp[a[1]-1]);return 0;
}