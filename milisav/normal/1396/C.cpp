#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 2000000
using namespace std;
long long dp[2];
long long tp[2];
long long inf=1e17;
int n;
long long r1,r2,r3;
long long d;
long long a[maxn];
int main() {
    dp[0]=0;
    dp[1]=inf;
    scanf("%d",&n);
    scanf("%lld %lld %lld",&r1,&r2,&r3);
    scanf("%lld",&d);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    long long ans=inf;
    for(int i=1;i<=n;i++) {
        if(i<n) {
            tp[0]=tp[1]=inf;
            tp[0]=min(tp[0],dp[0]+r2+d+d+r1+d);
            tp[0]=min(tp[0],dp[1]+r2+d+r1+d+r1+d);
            tp[0]=min(tp[0],dp[0]+(a[i]+1)*r1+d+d+r1+d);
            tp[0]=min(tp[0],dp[1]+(a[i]+1)*r1+d+r1+d+r1+d);
            tp[0]=min(tp[0],dp[0]+a[i]*r1+r3+d);
            tp[0]=min(tp[0],dp[1]+a[i]*r1+r3+d+r1+d+d);
            tp[1]=min(tp[1],dp[0]+r2+d);
            tp[1]=min(tp[1],dp[1]+r2+d+r1+d+d);
            tp[1]=min(tp[1],dp[0]+(a[i]+1)*r1+d);
            tp[1]=min(tp[1],dp[1]+(a[i]+1)*r1+d+r1+d+d);
            dp[0]=tp[0];
            dp[1]=tp[1];
        }
        else {
            ans=min(ans,dp[0]+r2+d+d+r1);
            ans=min(ans,dp[1]+r2+d+r1+d+r1);
            ans=min(ans,dp[0]+(a[i]+1)*r1+d+d+r1);
            ans=min(ans,dp[1]+(a[i]+1)*r1+d+r1+d+r1);
            ans=min(ans,dp[0]+a[i]*r1+r3);
            ans=min(ans,dp[1]+a[i]*r1+r3+d+r1);
        }
    }
    printf("%lld",ans);
	return 0;
}