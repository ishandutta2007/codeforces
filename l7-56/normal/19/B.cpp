#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;

const int maxn=2010;
ll dp[maxn*2];
struct node{
	ll w,t;
}a[maxn];
ll n,mxt,ans=1e18;

signed main(){
	scanf("%lld", &n);
	memset(dp,0x7f,sizeof dp);
	dp[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%lld%lld", &a[i].t, &a[i].w);a[i].t++;
		mxt=max(mxt,a[i].t);
	}
	for(int i=1;i<=n;++i)
		for(int j=n+mxt;j>=a[i].t;--j)
		 dp[j]=min(dp[j],dp[j-a[i].t]+a[i].w);
	for(int i=n;i<=n+mxt;++i)
	 ans=min(ans,dp[i]);
	printf("%lld", ans);
	return 0;
}