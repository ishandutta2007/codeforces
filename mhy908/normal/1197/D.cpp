#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;
typedef long long LL;
int n, m;
LL k, arr[300010];
LL num, ans;
LL dp[300010];
int st[300010];
LL slide()
{
    dp[0]=0;
    st[0]=1;
    LL ret=0;
    for(int i=1; i<=n; i++){
        dp[i]=max(dp[i-1], 0LL)+arr[i];
        if(dp[i-1]<=0)st[i]=i;
        else st[i]=st[i-1];
        if((i-st[i]+1)%m)ret=max(ret, dp[i]-k);
        else ret=max(ret, dp[i]);
    }
    return ret;
}
int main()
{
    scanf("%d %d %11d", &n, &m, &k);
    for(int i=1; i<=n; i++){
        scanf("%lld", &arr[i]);
    }
    for(int i=1; i<=m; i++){
        for(int j=i; j<=n; j+=m){
            arr[j]-=k;
        }
        LL maxmax=slide();
        ans=max(ans, maxmax);
        for(int j=i; j<=n; j+=m){
            arr[j]+=k;
        }
    }
    printf("%lld", ans);
}
/*
10 3 5
-1 2 10 7 -13 -21 5 -6 -2 1
*/